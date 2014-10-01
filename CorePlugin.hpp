#ifndef CorePlugin_HPP
#define CorePlugin_HPP

#include <QObject>
#include <QtPlugin>

#include <iris/CommandPlugin.hpp>

namespace iris
{
	class CorePlugin : public QObject, public CommandPlugin
	{
	private:
		Q_OBJECT
		Q_PLUGIN_METADATA(IID CommandPlugin_iid FILE "plugin.json")
		Q_INTERFACES(CommandPlugin)
	public:
		CorePlugin();
		// CommandPlugin interface
		~CorePlugin();
		QList<CommandPluginFactory*> commands() const;
		QString name();
	};
}

#endif // CorePlugin_HPP"

