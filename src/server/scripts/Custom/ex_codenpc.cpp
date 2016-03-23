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
    
    
    void pruefen(Player * player, bool korrekt){
        
        if(korrekt){
            
            QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `spieler`,`playerid`, `accountid`,`anzahl`, `richtig`, `falsch` FROM `spielerantworten` WHERE `accountid` = '%u'", player->GetSession()->GetAccountId());
            
            if(result){
                
                Field* felder = result->Fetch();
                uint32 accid = felder[3].GetUInt32();
                uint32 anzahl = felder[4].GetUInt32();
                uint32 korrekt = felder[5].GetUInt32();
                
                anzahl++;
                korrekt++;
                
                CharacterDatabase.PExecute("UPDATE spielerantworten SET anzahl = '%u' WHERE account = '%u'", anzahl, accid );
                CharacterDatabase.PExecute("UPDATE spielerantworten SET korrekt = '%u' WHERE account = '%u'", korrekt, accid);
                
                player->GetSession()->SendNotification("Geschafft");
                
            }
            
            else{
                
                CharacterDatabase.PExecute("Insert INTO spielerantworten (spieler,playerid, accountid, anzahl, richtig, falsch) Values ('%s', '$u', '%u', '%u','%u','%u')",player->GetSession()->GetPlayerName(), player->GetGUID(), player->GetSession()->GetAccountId(), 1,1, 0);
                
                player->GetSession()->SendNotification("Deine Antwort war richtig");
                return;
                
            }
            
            
            
            
            
        }
        
        
        if(!korrekt){
            QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `spieler`,`playerid`, `accountid`,`anzahl`, `richtig`, `falsch` FROM `spielerantworten` WHERE `accountid` = '%u'", player->GetSession()->GetAccountId());
            
            if(result){
                
                Field* felder = result->Fetch();
                uint32 accid = felder[3].GetUInt32();
                uint32 anzahl = felder[4].GetUInt32();
                uint32 falsch = felder[6].GetUInt32();
                
                anzahl++;
                falsch++;
                
                CharacterDatabase.PExecute("UPDATE spielerantworten SET playerid = '%u' WHERE account = '%u'", player->GetGUID(), accid );
                CharacterDatabase.PExecute("UPDATE spielerantworten SET anzahl = '%u' WHERE account = '%u'", anzahl, accid );
                CharacterDatabase.PExecute("UPDATE spielerantworten SET falsch = '%u' WHERE account = '%u'", falsch, accid);
                player->GetSession()->SendNotification("Deine Antwort war falsch");
                return;
            }
            
            
            else{
                
                CharacterDatabase.PExecute("Insert INTO spielerantworten (spieler,playerid, accountid, anzahl, richtig, falsch) Values ('%s', '$u', '%u', '%u','%u','%u')",player->GetSession()->GetPlayerName(), player->GetGUID(), player->GetSession()->GetAccountId(), 1,0, 1);
                
                player->GetSession()->SendNotification("Deine Antwort war falsch");
                return;
                
                
            }
        }

        
        
        }
    
    
   
    bool OnGossipHello(Player *player, Creature* _creature)
    {
        player->ADD_GOSSIP_ITEM(7,"1", GOSSIP_SENDER_MAIN,0);
        player->ADD_GOSSIP_ITEM(7,"Hallo", GOSSIP_SENDER_MAIN,1);
        player->ADD_GOSSIP_ITEM_EXTENDED(7, "Code eingeben" , GOSSIP_SENDER_MAIN, 2, "Antwort", 0,true);
        player->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
        return true;
    }
    
    
    bool OnGossipSelectCode(Player * player, Creature* /*creature*/, uint32 /*sender*/, uint32 action, const char* code){
        
        switch(action){
            
            case 0:
            {
                player->GetSession()->SendNotification("1");
            }
                
            case 1:
            {
                player->GetSession()->SendNotification("Hallo");
            }
            
            
            case 2:
            {
                uint32 nr = 1 + (std::rand() % (2 - 1 + 1));
        
                if(action == 2){
            
                    std::string codes = code;
                    //QueryResult result = CharacterDatabase.PQuery("SELECT `id`, `nr`,`frage`, `antwort` FROM `antworten` WHERE `nr` = '%u'", nr);
            
                    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_FRAGEN);
                    stmt->setInt32(0,nr);
                    PreparedQueryResult ergebnis = CharacterDatabase.Query(stmt);
            
                    Field* felder = ergebnis->Fetch();
                    std::string frage = felder[2].GetString();
                    std::string antwort = felder[3].GetString();
            
                   
                    std::ostringstream ss;
                    ss << "Deine Frage lautet: " << frage;
                    ChatHandler(player->GetSession()).PSendSysMessage(ss.str().c_str(), player->GetName());
            
                    if(codes == antwort){
                        pruefen(player, true);
                    }
                    
                    if(codes == "1111"){
                        player->GetSession()->SendNotification("Testseqenz erfolgreich");
                    }
            
                    if(codes != antwort){
                        pruefen(player,false);
                    }
            
                    return true;
                }
        
            }
        
        return true;
        }
    }
    
    
};


void AddSC_codenpc()
{
    new codenpc();
}