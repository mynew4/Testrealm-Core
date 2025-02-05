
DELETE FROM ``game_tele` WHERE `id` BETWEEN 5000 AND 5008;

REPLACE INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) 
VALUES 
('5000', '-9787.54','2130.62', '10.94', '0.38', '0', 'insel'),
('5001', '5631.87', '2479.79', '708.69', '0.56', '632', 'verschlinger'),
('5002', '-797.33','1492.70', '104.54', '1.05', '0', 'ausstattung'),
('5003', '-10675.20', '397.34', '35.22', '5.65', '0', 'rumu'),
('5004', '-81.97', '-42.45', '270.42', '0.04', '37', 'raid'),
('5005', '-793.66', '1565.25', '19.87', '3.35', '0', 'pvpareal'),
('5006', '-12556.57', '-1366.96', '41.56', '1.02', '0', 'orrig'),
('5007', '3077.53', '-3686.30', '546.97', '3.9', '571', 'extator'),
('5008', '3073.07', '-3689.94', '549.40', '1.12', '571', 'questnpc'),
('5009', '5866.76', '2107.31', '636.00', '3.64', '571', 'icc');