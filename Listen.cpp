#include "Listen.hpp"
#include <ircmessage.h>
#include <QDebug>

namespace iris
{
	QString Listen::mSyntax = "LISTEN <command> (<args...>)";

	Listen::Listen() : mQuiet(false), mPayAttention(true)
	{
	}
	void Listen::exec()
	{
	}
	void Listen::messageRecieved(IrcPrivateMessage* msg)
	{
		this->setTarget(msg->target());
		QString lowerContent = msg->content().toLower();

		if(lowerContent.contains("iris"))
		{
			if(mPayAttention)
			{
				if((lowerContent.contains("hello") || lowerContent.contains("hi") | lowerContent.contains("hey")))
				{
					emit printLine(mTarget, "Hi " + msg->nick() + "!");
				}
				else if(lowerContent.contains("be quiet"))
				{
					emit printLine(mTarget, "Alright. I'll quieten down.");
					mQuiet = true;
				}
				else if(lowerContent.contains("how's it going") || lowerContent.contains("how are you?"))
				{
					maybeSay("Oh, the same as ever. Life in a box is a little dull, you know?");
				}
				else if(lowerContent.contains("chat") || lowerContent.contains("talk") || lowerContent.contains("natter"))
				{
					mQuiet = false;
					maybeSay("OK. I'll be Mr Talkative from now on!");
				}
				else if(lowerContent.endsWith("stop listening"))
				{
					emit printLine(mTarget, "You want to talk in private? Sure.");
					mPayAttention = false;
				}
			}
			else if((lowerContent.contains("pay attention") || lowerContent.contains("listen")) && !lowerContent.contains("stop"))
			{
				mPayAttention = true;
				emit printLine(mTarget, "I'm listening.");
			}
		}
	}
	QString Listen::syntax()
	{
		return mSyntax;
	}
	void Listen::maybeSay(QString line)
	{
		if(!mQuiet)
		{
			emit printLine(mTarget, line);
		}
	}
}

