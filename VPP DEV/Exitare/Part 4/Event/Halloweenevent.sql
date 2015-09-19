DELETE FROM `game_event` WHERE `eventEntry` = 71;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`)
VALUES (71, '2015-10-21 21:00:00', '2030-11-10 20:00:00', '527040', '28740', '0','Exi Halloweenevent', '0');

DELETE FROM `game_event_creature_quest` WHERE `eventEntry` = 71;
INSERT INTO `game_event_creature_quest` (`eventEntry`, `id`, `quest`) VALUES 
('71', '800004', '900500'),
('71', '800004', '900501');

