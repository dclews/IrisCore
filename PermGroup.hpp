#ifndef PERMGROUP_HPP
#define PERMGROUP_HPP

#include <QJsonObject>
#include <QList>
#include <QString>

namespace iris
{
	class PermGroup
	{
	private:
		QString mGroupName;
		QList<QString> mAuthorisedCommands;
	public:
		PermGroup();
		void read(const QJsonObject& json);
		void write(QJsonObject& json) const;
		void print() const;

		QString groupname() const;
		const QList<QString>& authorisedCommands() const;
	};
}

#endif // PERMGROUP_HPP
