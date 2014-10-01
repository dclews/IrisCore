#include "PermUser.hpp"
#include <QJsonArray>
#include <QDebug>

namespace iris
{
	PermUser::PermUser()
	{
	}
	void PermUser::read(const QJsonObject& json)
	{
		mUserName = json["username"].toString();
		mPassword = json["password"].toString();
		mGroupName = json["group"].toString();

		for(QJsonValue command : json["authorisedCommands"].toArray())
		{
			mAuthorisedCommands.push_back(command.toString());
		}
	}
	void PermUser::write(QJsonObject& json) const
	{
		json["username"] = mUserName;
		json["password"] = mPassword;
		json["group"] = mGroupName;

		QJsonArray commandArray;
		for(QString command : mAuthorisedCommands)
		{
			commandArray.append(command);
		}
		json["authorisedCommands"] = commandArray;
	}
	void PermUser::print() const
	{
		qDebug() << mUserName;
		qDebug() << mPassword;
		qDebug() << mGroupName;
		qDebug() << mAuthorisedCommands;
	}

	QString PermUser::username() const
	{
		return mUserName;
	}

	QString PermUser::password() const
	{
		return mPassword;
	}

	QString PermUser::groupname() const
	{
		return mGroupName;
	}

	const QList<QString>&PermUser::authorisedCommands() const
	{
		return mAuthorisedCommands;
	}
}
