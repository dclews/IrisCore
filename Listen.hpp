#ifndef LISTEN_HPP
#define LISTEN_HPP

#include <QObject>
#include <iris/ListenerCommand.hpp>
#include <QMap>
#include <QList>

namespace iris
{
	class Listen : public ListenerCommand
	{
	private:
		Q_OBJECT
//		QMap<QString, QList<QString>> mTranscriptionList;
		bool mQuiet;
		bool mPayAttention;
		void maybeSay(QString line);
	public:
		explicit Listen();
		static QString mSyntax;

	signals:
		void printLine(QString target, QString line);
		void commandDone(int exitCode);

	public slots:
		// ASyncCommand interface
		QString syntax();
		void exec();

		// ListenerCommand interface
	public slots:
		void messageRecieved(IrcPrivateMessage* msg);
	};
}

#endif // LISTEN_HPP

