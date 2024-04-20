#include "Q4.h"

void Game::addItemToPlayer(const std::string& recipient, uint16_t itemId)
{
    Player* player = g_game.getPlayerByName(recipient);

    if (!player) 
    {
        player = new Player(nullptr);

        if (!IOLoginData::loadPlayerByName(player, recipient)) return;
    }

    Item* item = Item::CreateItem(itemId);
    if (!item) return;

    g_game.internalAddItem(player->getInbox(), item, INDEX_WHEREEVER, FLAG_NOLIMIT);

    if (player->isOffline()) 
    {
        IOLoginData::savePlayer(player);
    }

    delete(player); // Releasing This Local Pointer For Memory Leak Issue
    delete(item); // Releasing This Local Pointer For Memory Leak Issue
}


int main()
{
    g_game.addItemToPlayer("Dev", 21);
    std::cout<<"Hello From Q4"<<std::endl;

    std::cout<<std::endl;

    std::cout<<"Ans: To Fix Memory Leaks We Need To Release Memory For Pointers Like Player* & Item* By delete() Method "<<std::endl;

    std::cout<<std::endl;
    return 0;
}