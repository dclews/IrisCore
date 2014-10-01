#include "ListenFactory.hpp"
#include "Listen.hpp"

namespace iris
{
	ListenFactory::ListenFactory()
	{
	}
	command_type ListenFactory::commandType()
	{
		return Listener;
	}
	ASyncCommand* ListenFactory::newCommand()
	{
		return new Listen;
	}

	QString ListenFactory::syntax()
	{
		return Listen::mSyntax;
	}
}

