/*Q4 - Assume all method calls work fine. Fix the memory leak issue in below method

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

}
*/

#include <iostream>
#include <string>
#include <vector>

enum INDEX
{
    INDEX_FIRST,
    INDEX_LAST,
    INDEX_WHEREEVER
};

enum FLAG
{
    FLAG_LIMITED,
    FLAG_NON_DUPLICATE,
    FLAG_NOLIMIT
};

class Game;
class Item;

class Player
{
    public:
    Player(Game* gameInstance, std::string Name = "Player21", std::string Inbox = "Mail")
    {
        this->gameInstance = gameInstance;
        this->Name = Name;
        this->Inbox = Inbox;
    };

    bool isOffline()
    {
        return status;
    };

    std::string& getInbox()
    {
        return Inbox;
    };

    std::string& getName()
    {
        return Name;
    };

    void UpdateStatus(bool NewStatus)
    {
        status = NewStatus;
    };

    private:

    Game* gameInstance = nullptr;
    std::string Name;
    bool status;
    std::string Inbox;

};

class Game
{
    public:
        void Game::addItemToPlayer(const std::string& recipient, uint16_t itemId);

        Player* getPlayerByName(const std::string& recipient)
        {
            for (auto player : PlayerPool)
                if (player->getName() == recipient) return player;

            return nullptr;
        };

        void internalAddItem(std::string& Inbox, Item* item, INDEX Index, FLAG Flag)
        {

        };

        std::vector<Player*> PlayerPool;

}g_game;

class IOLoginData
{
    public:
    static bool loadPlayerByName(Player* player, const std::string& recipient)
    {
        for (auto poolItem : g_game.PlayerPool)
        {
            if (poolItem->getName() == recipient)
            {
                player = poolItem;
                return true;
            }
        }
                
        return false;
    };
    static void savePlayer(Player* player)
    {

    };
};

class Item
{
    public:

        Item(uint16_t itemId)
        {
            this->itemID = itemId;
        };

        static Item* CreateItem(uint16_t itemId)
        {
            return new Item(itemId);
        };

    private:
        uint16_t itemID;
};