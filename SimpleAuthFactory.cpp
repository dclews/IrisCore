#include "SimpleAuthFactory.hpp"
#include "SimpleAuth.hpp"

namespace iris
{
	SimpleAuthFactory::SimpleAuthFactory()
	{
	}
	ASyncCommand* SimpleAuthFactory::newCommand()
	{
		return new SimpleAuth;
	}

	QString SimpleAuthFactory::syntax()
	{
		return SimpleAuth::mSyntax;
	}

	command_type SimpleAuthFactory::commandType()
	{
		return AuthManager;
	}
}

