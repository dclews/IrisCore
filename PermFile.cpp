#include "PermFile.hpp"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

namespace iris
{
	PermFile::PermFile(QString path) : mFile(path)
	{
	}
	void PermFile::read()
	{
		if(!mFile.exists())
		{
			qCritical() << "[AUTH] PermFile" << mFile.fileName() << "does not exist";
			return;
		}

		mFile.open(QFile::ReadOnly);

		QByteArray permData = mFile.readAll();
		QJsonDocument json(QJsonDocument::fromJson(permData));
		QJsonObject jsonObj = json.object();

		const QJsonArray puArray = jsonObj["users"].toArray();
		for(int i=0;i<puArray.size();++i)
		{
			PermUser pu;
			pu.read(puArray[i].toObject());
//			pu.print();
			mUsers[pu.username()] = pu;
		}
		const QJsonArray pgArray = jsonObj["groups"].toArray();
		for(int i=0;i<pgArray.size();++i)
		{
			PermGroup pg;
			pg.read(pgArray[i].toObject());
//			pg.print();
			mGroups[pg.groupname()] = pg;
		}

		mFile.close();
	}
	void PermFile::write()
	{
		QJsonObject json;

		QJsonArray userArray;
		for(const PermUser& pu : mUsers)
		{
			QJsonObject puJson;
			pu.write(puJson);
			userArray.append(puJson);
		}
		json["users"] = userArray;

		QJsonArray groupArray;
		for(const PermGroup& pg : mGroups)
		{
			QJsonObject pgJson;
			pg.write(pgJson);
			groupArray.append(pgJson);
		}
		json["groups"] = userArray;

		QJsonDocument doc(json);

		mFile.open(QFile::WriteOnly);
		mFile.write(doc.toJson());

		mFile.close();
	}

	bool PermFile::userHasAuthorisationForCommand(QString user, QString command)
	{
		const PermUser& permUser = mUsers[user];
		const PermGroup& permGroup = mGroups[mUsers[user].groupname()];

		if(permUser.authorisedCommands().contains("ALL") || permGroup.authorisedCommands().contains("ALL"))
		{
			qDebug() << "[AUTH]" << user << "has ALL perm. Returning true.";
			return true;
		}
		if(permUser.authorisedCommands().contains(command) || permGroup.authorisedCommands().contains(command))
		{
			qDebug() << "[AUTH]" << user << "has matching perm. Returning true.";
			return true;
		}
		return false;
	}

	bool PermFile::authenticate(QString user, QString password)
	{
		const PermUser& permUser = mUsers[user];
		return permUser.password() == password;
	}
}
