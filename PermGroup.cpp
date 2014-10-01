#include "PermGroup.hpp"
#include <QJsonArray>
#include <QDebug>

namespace iris
{
	PermGroup::PermGroup()
	{
	}

	void PermGroup::read(const QJsonObject& json)
	{
		mGroupName = json["groupname"].toString();

		for(QJsonValue command : json["authorisedCommands"].toArray())
		{
			mAuthorisedCommands.push_back(command.toString());
		}
	}

	void PermGroup::write(QJsonObject& json) const
	{
		json["groupname"] = mGroupName;

		QJsonArray commandArray;
		for(QString command : mAuthorisedCommands)
		{
			commandArray.append(command);
		}
		json["authorisedCommands"] = commandArray;
	}
	void PermGroup::print() const
	{
		qDebug() << mGroupName;
		qDebug() << mAuthorisedCommands;
	}

	QString PermGroup::groupname() const
	{
		return mGroupName;
	}
	const QList<QString>&PermGroup::authorisedCommands() const
	{
		return mAuthorisedCommands;
	}
}
