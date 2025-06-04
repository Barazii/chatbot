#include <boost/test/unit_test.hpp>
#include <chatbot.h>
#include <iostream>
#include <sstream>

struct ChatBotTestsFixture
{
    std::stringstream buffer;
    std::streambuf *old;
    ChatBotTestsFixture()
    {
        // Redirect cout to our stringstream
        old = std::cout.rdbuf(buffer.rdbuf());
    }
    ~ChatBotTestsFixture()
    {
        // Restore cout
        std::cout.rdbuf(old);
    }
};

BOOST_FIXTURE_TEST_SUITE(ChatBotTests, ChatBotTestsFixture)

BOOST_AUTO_TEST_CASE(test_constructor_without_arguments)
{
    // Test default constructor
    ChatBot chatbot;
    BOOST_CHECK(buffer.str().find("ChatBot Constructor Without Memory Allocation") != std::string::npos);
    buffer.str("");

    BOOST_ASSERT(chatbot.GetChatLogicHandle() == nullptr);
    BOOST_ASSERT(chatbot.GetImageHandle() == NULL);
}

BOOST_AUTO_TEST_CASE(test_constructor_with_arguments)
{
    // Test constructor with filename
    ChatBot chatbot("../images/user.png");
    BOOST_CHECK(buffer.str().find("ChatBot Constructor With Memory Allocation") != std::string::npos);
    buffer.str("");

    BOOST_ASSERT(chatbot.GetChatLogicHandle() == nullptr);
    BOOST_ASSERT(chatbot.GetImageHandle() != NULL);
}

BOOST_AUTO_TEST_CASE(test_copy_constructor_with_argument)
{
    ChatBot chatbot("../images/user.png");
    buffer.str("");

    // Test copy constructor
    ChatBot chatbot3(chatbot);
    BOOST_CHECK(buffer.str().find("ChatBot Copy Constructor") != std::string::npos);
    buffer.str("");

    BOOST_ASSERT(chatbot3.GetImageHandle() != NULL);

    if (chatbot.GetChatLogicHandle() == nullptr)
        BOOST_ASSERT(chatbot3.GetChatLogicHandle() == nullptr);
    if (chatbot.GetChatLogicHandle() != nullptr)
        BOOST_ASSERT(chatbot3.GetChatLogicHandle() != nullptr);
}

BOOST_AUTO_TEST_CASE(test_copy_constructor_without_argument)
{
    ChatBot chatbot;
    buffer.str("");

    // Test copy constructor
    ChatBot chatbot3(chatbot);
    BOOST_CHECK(buffer.str().find("ChatBot Copy Constructor") != std::string::npos);
    buffer.str("");

    BOOST_ASSERT(chatbot3.GetChatLogicHandle() == nullptr);
    BOOST_ASSERT(chatbot3.GetImageHandle() == NULL);
}

BOOST_AUTO_TEST_CASE(test_move_constructor_with_argument)
{
    ChatBot chatbot2("../images/user.png");
    buffer.str("");

    // Test move constructor
    ChatBot chatbot4(std::move(chatbot2));
    BOOST_CHECK(buffer.str().find("ChatBot Move Constructor") != std::string::npos);
    buffer.str("");

    BOOST_ASSERT(chatbot2.GetImageHandle() == NULL);
    BOOST_ASSERT(chatbot4.GetImageHandle() != NULL);

    BOOST_ASSERT(chatbot2.GetChatLogicHandle() == nullptr);
    BOOST_ASSERT(chatbot4.GetChatLogicHandle() == nullptr);
}

BOOST_AUTO_TEST_CASE(test_move_constructor_without_argument)
{
    ChatBot chatbot2;
    buffer.str("");

    // Test move constructor
    ChatBot chatbot4(std::move(chatbot2));
    BOOST_CHECK(buffer.str().find("ChatBot Move Constructor") != std::string::npos);
    buffer.str("");
}

BOOST_AUTO_TEST_CASE(test_copy_assignment)
{
    ChatBot chatbot1;
    buffer.str("");

    ChatBot chatbot2("../images/user.png");
    buffer.str("");

    // Test copy assignment
    chatbot1 = chatbot2;
    BOOST_CHECK(buffer.str().find("ChatBot Copy Assignment Operator") != std::string::npos);
    buffer.str("");

    BOOST_ASSERT(chatbot1.GetImageHandle() != NULL);
    BOOST_ASSERT(chatbot1.GetChatLogicHandle() == nullptr);

    BOOST_ASSERT(chatbot2.GetImageHandle() != NULL);
    BOOST_ASSERT(chatbot2.GetChatLogicHandle() == nullptr);
}

BOOST_AUTO_TEST_CASE(test_move_assignment)
{
    ChatBot chatbot1;
    buffer.str("");

    ChatBot chatbot2("../images/user.png");
    buffer.str("");

    // Test move assignment
    chatbot1 = std::move(chatbot2);
    BOOST_CHECK(buffer.str().find("ChatBot Move Assignment Constructor") != std::string::npos);
    buffer.str("");

    BOOST_ASSERT(chatbot1.GetImageHandle() != NULL);
    BOOST_ASSERT(chatbot2.GetImageHandle() == NULL);

    BOOST_ASSERT(chatbot1.GetChatLogicHandle() == nullptr);
    BOOST_ASSERT(chatbot2.GetChatLogicHandle() == nullptr);
}

BOOST_AUTO_TEST_CASE(test_destructor)
{
    // Test default constructor
    ChatBot chatbot1;
    buffer.str("");

    chatbot1.~ChatBot();
    BOOST_CHECK(buffer.str().find("ChatBot Destructor") != std::string::npos);
    buffer.str("");
}

BOOST_AUTO_TEST_SUITE_END()