#ifndef AUTHMANAGERFACTORY_HPP
#define AUTHMANAGERFACTORY_HPP

#include <QObject>
#include <iris/CommandPluginFactory.hpp>

namespace iris
{
	class SimpleAuthFactory : public QObject, public CommandPluginFactory
	{
		Q_OBJECT
	public:
		explicit SimpleAuthFactory();
	public slots:
		ASyncCommand* newCommand();
		QString syntax();
		command_type commandType();
	};
}

#endif // AUTHMANAGERFACTORY_HPP
