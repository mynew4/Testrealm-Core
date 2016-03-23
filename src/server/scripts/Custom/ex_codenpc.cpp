#include "AccountMgr.h"
#include "time.h"
#include <stdio.h>
#include "Bag.h"
#include "Common.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "DBCStructure.h"
#include "Define.h"
#include "Field.h"
#include "GameEventMgr.h"
#include "Item.h"
#include "ItemPrototype.h"
#include "Language.h"
#include "Log.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QueryResult.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "Transaction.h"
#include "WorldSession.h"
#include <sstream>
#include <string>
#include <stdlib.h>






class codenpc : public CreatureScript
{
 

public:
    codenpc() : CreatureScript("codenpc") { }
    
    
    
    
   
    bool OnGossipHello(Player *player, Creature* _creature)
    {
        player->ADD_GOSSIP_ITEM(7,"Gib mir die NR aus", GOSSIP_SENDER_MAIN, 0);
        player->ADD_GOSSIP_ITEM(7,"Stelle mir eine Frage", GOSSIP_SENDER_MAIN,1);
        player->ADD_GOSSIP_ITEM_EXTENDED(7, "Code eingeben" , GOSSIP_SENDER_MAIN, 2, "Antwort", 0,true);
        player->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
        return true;
    }
    
    
    bool OnGossipSelectCode(Player * player, Creature* /*creature*/, uint32 /*sender*/, uint32 action, const char* code){
        
        switch(action){
            
            case 0:
            {
                std::ostringstream uu;
                uint32 nr = 1 + (std::rand() % (10 - 1 + 1));
                ChatHandler(player->GetSession()).PSendSysMessage("ZIemliche nervig!", player->GetName());
                return true;
                
            }break;
                
            
            case 1:
                {
                    uint32 nr = 1 + (std::rand() % (10 - 1 + 1));
                    PreparedStatement* selfragen = CharacterDatabase.GetPreparedStatement(CHAR_SEL_FRAGEN_NACH_NR);
                    selfragen->setInt32(0,nr);
                    PreparedQueryResult ergebnis = CharacterDatabase.Query(selfragen);
                
                    //PrepareStatement(CHAR_SEL_FRAGEN_NACH_NR, "SELECT `id`, `nr`,`frage`, `antwort` FROM `antworten` WHERE `nr` = ?", CONNECTION_SYNCH);

                    Field* felder = ergebnis->Fetch();
                    std::string frage = felder[2].GetString();
                
                    TC_LOG_INFO(nr);
                    TC_LOG_INFO(frage);
                    
                    std::ostringstream ss;
                    ss << "Deine Frage lautet: " << frage;
                    ChatHandler(player->GetSession()).PSendSysMessage(ss.str().c_str(), player->GetName());
                    
                    player->PlayerTalkClass->SendCloseGossip();
                    return true;
                
                }break;
            
            
            case 2:
                {
                
                    std::string codes = code;
                
                    if(codes == "1111"){
                        player->GetSession()->SendNotification("Hallo");
                        return true;
                    }
                    
                    PreparedStatement* selantwort = CharacterDatabase.GetPreparedStatement(CHAR_SEL_FRAGEN_NACH_ANTWORT);
                    selantwort->setString(0, codes);
                    PreparedQueryResult ergebnis = CharacterDatabase.Query(selantwort);
                    
                    //Field* feld = ergebnis->Fetch();
                    
                    if(!ergebnis){
                        player->GetSession()->SendNotification("Falsch");
                        return false;
                    }
                    
                    if(ergebnis){
                        player->GetSession()->SendNotification("Korrekt");
                        return true;
                    }
                    
                    
                
                }break;
        
                return true;
        
            }
    
        return true;
    }
    
};


void AddSC_codenpc()
{
    new codenpc();
}