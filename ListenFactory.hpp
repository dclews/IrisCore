#ifndef LISTENFACTORY_HPP
#define LISTENFACTORY_HPP

#include <QObject>
#include <iris/CommandPluginFactory.hpp>

namespace iris
{
	class ListenFactory : public QObject, public CommandPluginFactory
	{
	private:
		Q_OBJECT
	public:
		explicit ListenFactory();
		command_type commandType();
	public slots:
		ASyncCommand* newCommand();
		QString syntax();
	};
}


#endif // LISTENFACTORY_HPP

