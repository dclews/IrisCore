#ifndef PERMUSER_HPP
#define PERMUSER_HPP

#include <QString>
#include <QJsonObject>
#include <QList>

namespace iris
{
	class PermUser
	{
	private:
		QString mUserName;
		QString mPassword;
		QString mGroupName;
		QList<QString> mAuthorisedCommands;
	public:
		PermUser();
		void read(const QJsonObject& json);
		void write(QJsonObject& json) const;
		void print() const;

		QString username() const;
		QString password() const;
		QString groupname() const;
		const QList<QString>& authorisedCommands() const;
	};
}

#endif // PERMUSER_HPP
