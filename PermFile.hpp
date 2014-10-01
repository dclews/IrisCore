#ifndef PERMISSIONFILE_HPP
#define PERMISSIONFILE_HPP

#include <QFile>
#include <QMap>
#include <QString>

#include "PermGroup.hpp"
#include "PermUser.hpp"

namespace iris
{
	class PermFile : public QObject
	{
	private:
		Q_OBJECT
		QFile mFile;
		QMap<QString, PermUser> mUsers;
		QMap<QString, PermGroup> mGroups;
	public:
		PermFile(QString path);
		void read();
		void write();
		bool userHasAuthorisationForCommand(QString user, QString command);
		bool authenticate(QString user, QString password);
	};
}

#endif // PERMISSIONFILE_HPP
