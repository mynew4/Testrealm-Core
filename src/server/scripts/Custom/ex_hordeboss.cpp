#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"
#include "Player.h"

enum eNums
{
	SPELL_FROSTSHOCK = 23115,
	SPELL_CHILL = 21098,
	SPELL_ICEBLOCK = 41590,
};

class horde_boss : public CreatureScript
{
public:
	horde_boss() : CreatureScript("hordeboss"){}

	CreatureAI * GetAI(Creature * pCreature) const
	{
		return new horde_bossAI(pCreature);
	}

	struct horde_bossAI : public ScriptedAI
	{
		horde_bossAI(Creature *c) : ScriptedAI(c){}

		uint32 Frostshock_Timer;
		uint32 Chill_Timer;

		int phase;
		int percentPassed;

		void Reset()
		{
			me->SetHealth(me->GetMaxHealth());
			phase = 1;
			percentPassed = 0;
			Frostshock_Timer = 8000;
			Chill_Timer = 3000;
		}
		void EnterCombat(Unit * /*who*/)
		{
			percentPassed = 1;
		}
		void JustDied(Unit* )
		{
			char msg[250];
			snprintf(msg, 250, "|cffff0000[Event System]|r Die |cff00ccff Allianz|r hat das Event gewonnen!");  
			sWorld->SendGlobalText(msg, NULL);
		}
		void UpdateAI(const uint32 uiDiff)
		{
			ScriptedAI::UpdateAI(uiDiff);

			if (!UpdateVictim())
				return;

			if (Frostshock_Timer <= uiDiff)
			{
				DoCast(me, SPELL_FROSTSHOCK);
				Frostshock_Timer = 15000;
			}
			else
				Frostshock_Timer -= uiDiff;
			DoMeleeAttackIfReady();

			if (Chill_Timer <= uiDiff)
			{
				DoCast(me, SPELL_CHILL);
				Chill_Timer = 3000;
			}
			else
				Chill_Timer -= uiDiff;
			DoMeleeAttackIfReady();

			if (me->GetHealthPct() <= 10 && percentPassed == 1)
			{
				DoCast(me, SPELL_ICEBLOCK, true);
				percentPassed = 2;
			}

			switch (phase)
			{
			case 1:
				if (percentPassed == 2)
				{
					phase = 2;
				}
				break;
			}
		}
	};
};

void AddSC_hordeboss()
{
	new horde_boss();
}