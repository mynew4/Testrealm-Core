DELETE FROM `game_event` WHERE `eventEntry` = 72;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`)
VALUES (72, '2015-09-19 12:40:00', '2030-11-10 20:00:00', '5', '2', '0','Exi`s Event', '1');

DELETE FROM `game_event_creature_quest` WHERE `eventEntry` = 72;
INSERT INTO `game_event_creature_quest` (`eventEntry`, `id`, `quest`) VALUES 
('72', '800004', '900800'),
('72', '800004', '900801');

