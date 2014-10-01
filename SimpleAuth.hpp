#ifndef AUTHMANAGER_HPP
#define AUTHMANAGER_HPP

#include <QObject>
#include <iris/ASyncCommand.hpp>
#include <iris/AuthenticationManager.hpp>
#include <QMap>
#include "PermFile.hpp"

namespace iris
{
	class SimpleAuth : public AuthenticationManager
	{
	private:
		Q_OBJECT

		PermFile pf;
		QMap<QString, QString> mNickUserMap;

	public:
		SimpleAuth();
		virtual ~SimpleAuth();
		static QString mSyntax;

	signals:
		void printLine(QString nick, QString line);
		void commandDone(int exitCode);

	public slots:
		// ASyncCommand interface
		QString syntax();
		void exec();

		// AuthenticationManager interface
	public slots:
		bool checkUserHasPermissionsForCommand(QString nick, QString command);
		bool loginUser(QString nick, QStringList params);
	};
}

#endif // AUTHMANAGER_HPP

