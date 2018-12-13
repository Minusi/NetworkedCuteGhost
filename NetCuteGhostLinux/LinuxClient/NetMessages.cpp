#include "NetMessages.h"



const char NetMeta::CHATTING = '~';
const char NetMeta::GAMECTRL = '%';
const char NetMeta::COMMAND = '#';
const char NetMeta::INTERPROC = '*';

const std::string NetMessage::LnxClient::GAME::UP = "%up";
const std::string NetMessage::LnxClient::GAME::DOWN = "%down";
const std::string NetMessage::LnxClient::GAME::LEFT = "%left";
const std::string NetMessage::LnxClient::GAME::RIGHT = "%right";

const std::string NetMessage::LnxClient::GAME::SLOWUP = "%slowup";
const std::string NetMessage::LnxClient::GAME::SLOWDOWN = "%slowdown";
const std::string NetMessage::LnxClient::GAME::SLOWLEFT = "%slowleft";
const std::string NetMessage::LnxClient::GAME::SLOWRIGHT = "%slowright";

const std::string NetMessage::LnxClient::GAME::STOP = "%stop";
const std::string NetMessage::LnxClient::GAME::DASH = "%dash";

const std::string NetMessage::LnxClient::CMD::QUIT = "#quit";




const std::string NetMessage::LnxServer::IPC::INDEX = "*index";