#include "CorePlugin.hpp"
#include "ListenFactory.hpp"
#include "SimpleAuthFactory.hpp"

namespace iris
{
	CorePlugin::CorePlugin()
	{
	}
	CorePlugin::~CorePlugin()
	{
	}
	QList<CommandPluginFactory*> CorePlugin::commands() const
	{
		QList<CommandPluginFactory*> commands;
		commands << new ListenFactory << new SimpleAuthFactory;
		return commands;
	}
	QString CorePlugin::name()
	{
		return "Core";
	}
}

