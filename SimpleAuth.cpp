#include "SimpleAuth.hpp"
#include <QDebug>

namespace iris
{
	QString SimpleAuth::mSyntax = "AUTH <user> <password>";

	SimpleAuth::SimpleAuth() : pf("./Perms.json")
	{
	}
	SimpleAuth::~SimpleAuth()
	{
	}
	void SimpleAuth::exec()
	{
		pf.read();
	}
	bool SimpleAuth::checkUserHasPermissionsForCommand(QString nick, QString command)
	{
		QString user = mNickUserMap.contains(nick) ? mNickUserMap[nick] : "guest";

		bool success = pf.userHasAuthorisationForCommand(user, command);
		if(!success)
		{
			qDebug() << "[AUTH] Nick" << nick << "User" << user << "TRIED TO USE" << command <<  "but was DENIED due to a lack of permissions.";
		}

		return success;
	}
	bool SimpleAuth::loginUser(QString nick, QStringList params)
	{
		QString username = params.at(1);
		QString password = params.at(2);

		if(pf.authenticate(username, password))
		{
			qDebug() << "[AUTH] Nick" << nick << "has logged in as user" << username;
			mNickUserMap[nick] = username;
			return true;
		}
		qDebug() << "[AUTH] Nick" << nick << "has FAILED TO LOGIN as user" << username;
		return false;
	}
	QString SimpleAuth::syntax()
	{
		return mSyntax;
	}
}
