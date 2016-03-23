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
    
    void Belohnung(Player* player, uint32 nr){
        
        
        /*
         TODO CHECK IF PLAYER HAS ANSWER THE QUESTION.
         
        */
        
        PreparedStatement* itemquery = CharacterDatabase.GetPreparedStatement(CHAR_SEL_FRAGEN_NACH_NR);
        itemquery->setInt32(0, nr);
        PreparedQueryResult result = CharacterDatabase.Query(itemquery);
        
        Field* feld = result->Fetch();
        uint32 belohnung = feld[4].GetInt32();
        uint32 anzahl = feld[5].GetInt32();
        
        Item* item = Item::CreateItem(belohnung, anzahl);
        uint32 uid = player->GetGUID();
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        item->SaveToDB(trans);
        MailDraft("Raetsel geloest", "Glueckwunsch. Du hast ein Raetsel geloest. Hier ist deine Belohnung.").AddItem(item)
        .SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
        CharacterDatabase.CommitTransaction(trans);
        return;

    }
    
    
   
    bool OnGossipHello(Player *player, Creature* _creature)
    {
        player->ADD_GOSSIP_ITEM_EXTENDED(7, "Code eingeben" , GOSSIP_SENDER_MAIN, 2, "Antwort", 0,true);
        player->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
        return true;
    }
    
    
    bool OnGossipSelectCode(Player * player, Creature* /*creature*/, uint32 /*sender*/, uint32 action, const char* code){
        
        switch(action){
            
            
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
                    
                    Field* feld = ergebnis->Fetch();
                    uint32 nr = feld[1].GetInt32();
                    
                    if(!ergebnis){
                        player->GetSession()->SendNotification("Falsch");
                        return false;
                    }
                    
                    if(ergebnis){
                        player->GetSession()->SendNotification("Korrekt");
                        Belohnung(player->GetSession()->GetPlayer(), nr);
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