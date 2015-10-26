#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells{
	SPELL_HEX = 66054,							// FLUCH
	SPELL_SHEEP = 59634,						// PENGUIN!
	SPELL_FLUCH_DER_PEIN = 65814,				// FLUCH alle 2 Sekunden 2k Schaden 
	SPELL_SPALTEN = 40504,						// bis zu 3 Ziele
	SPELL_SCHATTENWORT_SCHMERZ = 65541,			// MAGIE
	SPELL_RUESTUNG_ZERREISSEN = 74367,			// stackbar bis 5x
	SPELL_VERDERBNIS = 65810,					// MAGIE
	SPELL_FLEISCH_EINAESCHERN = 66237,			// 30k muessen weggeheilt werden sonst explodiert der Spell und fuegt AOE Feuerschaden zu
	SPELL_ZAUBERSCHILD = 33054,					// 75% weniger Zauberschaden BUFF
	SPELL_WIRBELWIND = 40219,					// 6 Sekunden Wirbelwind
	SPELL_VERDERBENDE_SEUCHE = 60588,			// STERBT EINFACH
	SPELL_WUNDGIFT = 65962,						// GIFT
	SPELL_HAMMER_DER_GERECHTIGKEIT = 66613		// STUN
};

enum Events{
	EVENT_HEX = 1,
	EVENT_SHEEP = 2,
	EVENT_FLUCH_DER_PEIN = 3,
	EVENT_SPALTEN = 4,
	EVENT_SCHATTENWORT_SCHMERZ = 5,
	EVENT_RUESTUNG_ZERREISSEN = 6,
	EVENT_VERDERBNIS = 7,
	EVENT_FLEISCH_EINAESCHERN = 8,
	EVENT_ZAUBERSCHILD = 9,
	EVENT_WIRBELWIND = 10,
	EVENT_VERDERBENDE_SEUCHE = 11,
	EVENT_WUNDGIFT = 12,
	EVENT_HAMMER_DER_GERECHTIGKEIT = 13
};

enum Phases{
	PHASE_ONE = 1,
	PHASE_TWO = 2,
	PHASE_THREE = 3,
	PHASE_FOUR = 4,
	PHASE_FIVE = 5
};

class anna : public CreatureScript{
public:
	anna() : CreatureScript("anna") { }

	struct annaAI : public ScriptedAI {

		annaAI(Creature* creature) : ScriptedAI(creature) {}

		void Reset() override
		{
			_events.Reset();
		}

		void EnterCombat(Unit* /*who*/) override
		{
			_events.SetPhase(PHASE_ONE);
			_events.ScheduleEvent(EVENT_FLUCH_DER_PEIN, 1000);
			_events.ScheduleEvent(EVENT_SPALTEN, 10000);
		}

		void DamageTaken(Unit* /*attacker*/, uint32& damage) override
		{
			if (me->HealthBelowPctDamaged(80, damage) && _events.IsInPhase(PHASE_ONE))
			{
				_events.SetPhase(PHASE_TWO);
				_events.ScheduleEvent(EVENT_SHEEP, 0);
				_events.ScheduleEvent(EVENT_FLUCH_DER_PEIN, 1000);
				_events.ScheduleEvent(EVENT_SPALTEN, 8000);
				_events.ScheduleEvent(EVENT_SCHATTENWORT_SCHMERZ, 10000);
			}

			if (me->HealthBelowPctDamaged(60, damage) && _events.IsInPhase(PHASE_TWO))
			{
				_events.SetPhase(PHASE_THREE);
				_events.ScheduleEvent(EVENT_VERDERBNIS, 500);
				_events.ScheduleEvent(EVENT_HEX, 1000);
				_events.ScheduleEvent(EVENT_HAMMER_DER_GERECHTIGKEIT, 20000);
				_events.ScheduleEvent(EVENT_WIRBELWIND, 21000);
			}

			if (me->HealthBelowPctDamaged(40, damage) && _events.IsInPhase(PHASE_THREE))
			{
				_events.SetPhase(PHASE_FOUR);
				_events.ScheduleEvent(EVENT_HAMMER_DER_GERECHTIGKEIT, 1000);
				_events.ScheduleEvent(EVENT_HEX, 1500);
				_events.ScheduleEvent(EVENT_SHEEP, 2500);
				_events.ScheduleEvent(EVENT_RUESTUNG_ZERREISSEN, 3000);
				_events.ScheduleEvent(EVENT_FLEISCH_EINAESCHERN, 10000);
				_events.ScheduleEvent(EVENT_SCHATTENWORT_SCHMERZ, 12000);
				_events.ScheduleEvent(EVENT_WIRBELWIND, 15000);
			}

			if (me->HealthBelowPctDamaged(20, damage) && _events.IsInPhase(PHASE_FOUR))
			{
				_events.SetPhase(PHASE_FIVE);
				_events.ScheduleEvent(EVENT_ZAUBERSCHILD, 0);
				_events.ScheduleEvent(EVENT_RUESTUNG_ZERREISSEN, 1000);
				_events.ScheduleEvent(EVENT_FLEISCH_EINAESCHERN, 2000);
				_events.ScheduleEvent(EVENT_VERDERBENDE_SEUCHE, 800);
				_events.ScheduleEvent(EVENT_WUNDGIFT, 1000);

			}
		}

		void JustDied(Unit* /*killer*/) override
		{
			char msg[250];
			snprintf(msg, 250, "|cffff0000[Boss System]|r Boss|cffff6060 Anna|r wurde getoetet! Der Respawn erfolgt in 7 Tagen.");
			sWorld->SendGlobalText(msg, NULL);
		}

		void UpdateAI(uint32 diff) override
		{
			if (!UpdateVictim())
				return;

			_events.Update(diff);

			while (uint32 eventId = _events.ExecuteEvent())
			{
				switch (eventId)
				{

				case EVENT_HEX:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 4)){
						DoCast(target, SPELL_HEX);
					}
					_events.ScheduleEvent(EVENT_HEX, 16000);
					break;

				case EVENT_SHEEP:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2)){
						DoCast(target, SPELL_SHEEP);
					}
					_events.ScheduleEvent(EVENT_SHEEP, 20000);
					break;

				case EVENT_FLUCH_DER_PEIN:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0)){	
						DoCast(target, SPELL_FLUCH_DER_PEIN);
					}
					_events.ScheduleEvent(EVENT_FLUCH_DER_PEIN, 14000);
					break;

				case EVENT_SPALTEN:
					DoCastVictim(SPELL_SPALTEN);
					_events.ScheduleEvent(EVENT_SPALTEN, 25000);
					break;

				case EVENT_SCHATTENWORT_SCHMERZ:
					DoCastToAllHostilePlayers(SPELL_SCHATTENWORT_SCHMERZ);
					_events.ScheduleEvent(EVENT_SCHATTENWORT_SCHMERZ, 20000);
					break;

				case EVENT_RUESTUNG_ZERREISSEN:
					DoCastVictim(SPELL_RUESTUNG_ZERREISSEN);
					_events.ScheduleEvent(EVENT_RUESTUNG_ZERREISSEN, 15000);
					break;

				case EVENT_VERDERBNIS:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0)){
						DoCast(target, SPELL_VERDERBNIS);
					}
					_events.ScheduleEvent(EVENT_VERDERBNIS, 17000);
					break;

				case EVENT_FLEISCH_EINAESCHERN:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0)){
						DoCast(target, SPELL_FLEISCH_EINAESCHERN);
					}
					_events.ScheduleEvent(EVENT_FLEISCH_EINAESCHERN, 15000);
					break;

				case EVENT_WIRBELWIND:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1)){
						DoCast(target, SPELL_WIRBELWIND);
					}
					_events.ScheduleEvent(EVENT_WIRBELWIND, 16000);
					break;

				case EVENT_VERDERBENDE_SEUCHE:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0)){
						DoCast(target, SPELL_VERDERBENDE_SEUCHE);
					}
					_events.ScheduleEvent(EVENT_VERDERBENDE_SEUCHE, 30000);
						break;

				case EVENT_WUNDGIFT:
					DoCastVictim(SPELL_WUNDGIFT);
					_events.ScheduleEvent(EVENT_WUNDGIFT, 10000);
					break;

				case EVENT_HAMMER_DER_GERECHTIGKEIT:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1)){
						DoCast(target, SPELL_HAMMER_DER_GERECHTIGKEIT);
					}
					_events.ScheduleEvent(EVENT_HAMMER_DER_GERECHTIGKEIT, 12000);
					break;

				case EVENT_ZAUBERSCHILD:
					DoCast(me, SPELL_ZAUBERSCHILD);
					_events.ScheduleEvent(EVENT_ZAUBERSCHILD, 30000);
					break;

				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}

	private:
		EventMap _events;
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new annaAI(creature);
	}

};

void AddSC_anna()
{
	new anna();
}