#ifndef CONVERSATION_HPP
#define CONVERSATION_HPP

#include <QJsonObject>
#include <ircmessage.h>

class Conversation
{
	QList<
public:
	Conversation();
	void append(IrcMessage* msg);
	void read(const QJsonObject& json);
	void write(QJsonObject& json) const;
	void print() const;
};

#endif // CONVERSATION_HPP
