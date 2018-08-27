#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "messages_order.h"

using namespace std;

// It'd be good to put the declarations for these classes
// in the header. However, the spec requires some functions
// consume std::strings and including <string> in the header
// wasn't the right thing to do.
// Additionally, keeping the class delcarations in this TU
// keeps line lengths shorter and reduces resolving, since
// Message is a common name.

class Message {
private:
    int m_id;
    string m_text;
public:
    Message (const string & text, int id);
    const string & get_text () const;
    const int get_id () const;
};

class MessageFactory {
private:
    int m_msg_id;
public:
    MessageFactory ();
    Message create_message(const string & text);
};

///////////////////////
// Message Impl

Message::Message (const string & text, int id) : m_text(text), m_id(id) {}
const string & Message::get_text () const { return m_text; }
const int Message::get_id () const { return m_id; }

bool operator< (Message a, Message b)
{
    return a.get_id() < b.get_id();
}

///////////////////////
// MessageFactory Impl

MessageFactory::MessageFactory () : m_msg_id(0) {}
Message MessageFactory::create_message (const string & text)
{
    Message msg(text, m_msg_id);
    return Message(text, m_msg_id++);
}

// START HACKERRANK LOCKED CODE
class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};

int hackerrank::messages_order ()
{
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
    return 0;
}
// END HACKERRANK LOCKED CODE
