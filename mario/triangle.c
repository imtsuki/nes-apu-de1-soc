#include "../notes.h"

const note_t TRIANGLE_NOTES[] = {
    {"D3", 0, 8, 0, -1},     {"D3", 9, 8, 0, -1},     {"D3", 27, 8, 0, -1},
    {"D3", 45, 8, 0, -1},    {"D3", 54, 8, 0, -1},    {"G4", 72, 8, 0, -1},
    {"G3", 108, 8, 0, -1},   {"G3", 144, 8, 0, -1},   {"E3", 171, 8, 0, -1},
    {"C3", 198, 8, 0, -1},   {"F3", 225, 8, 0, -1},   {"G3", 243, 8, 0, -1},
    {"F#3", 261, 8, 0, -1},  {"F3", 270, 8, 0, -1},   {"E3", 288, 8, 0, -1},
    {"C4", 300, 8, 0, -1},   {"E4", 312, 8, 0, -1},   {"F4", 324, 8, 0, -1},
    {"D4", 342, 8, 0, -1},   {"E4", 351, 8, 0, -1},   {"C4", 369, 8, 0, -1},
    {"A3", 387, 8, 0, -1},   {"B3", 396, 8, 0, -1},   {"G3", 405, 8, 0, -1},
    {"G3", 432, 8, 0, -1},   {"E3", 459, 8, 0, -1},   {"C3", 486, 8, 0, -1},
    {"F3", 513, 8, 0, -1},   {"G3", 531, 8, 0, -1},   {"F#3", 549, 8, 0, -1},
    {"F3", 558, 8, 0, -1},   {"E3", 576, 8, 0, -1},   {"C4", 588, 8, 0, -1},
    {"E4", 600, 8, 0, -1},   {"F4", 612, 8, 0, -1},   {"D4", 630, 8, 0, -1},
    {"E4", 639, 8, 0, -1},   {"C4", 657, 8, 0, -1},   {"A3", 675, 8, 0, -1},
    {"B3", 684, 8, 0, -1},   {"G3", 693, 8, 0, -1},   {"C3", 720, 8, 0, -1},
    {"G3", 747, 8, 0, -1},   {"C4", 774, 8, 0, -1},   {"F3", 792, 8, 0, -1},
    {"C4", 819, 8, 0, -1},   {"C4", 828, 8, 0, -1},   {"F3", 846, 8, 0, -1},
    {"C3", 864, 8, 0, -1},   {"E3", 891, 8, 0, -1},   {"G3", 918, 8, 0, -1},
    {"C4", 927, 8, 0, -1},   {"G5", 945, 8, 0, -1},   {"G5", 963, 8, 0, -1},
    {"G5", 972, 8, 0, -1},   {"G3", 990, 8, 0, -1},   {"C3", 1008, 8, 0, -1},
    {"G3", 1035, 8, 0, -1},  {"C4", 1062, 8, 0, -1},  {"F3", 1080, 8, 0, -1},
    {"C4", 1107, 8, 0, -1},  {"C4", 1116, 8, 0, -1},  {"F3", 1134, 8, 0, -1},
    {"C3", 1152, 8, 0, -1},  {"G#3", 1170, 8, 0, -1}, {"A#3", 1197, 8, 0, -1},
    {"C4", 1224, 8, 0, -1},  {"G3", 1251, 8, 0, -1},  {"G3", 1260, 8, 0, -1},
    {"C3", 1278, 8, 0, -1},  {"C3", 1296, 8, 0, -1},  {"G3", 1323, 8, 0, -1},
    {"C4", 1350, 8, 0, -1},  {"F3", 1368, 8, 0, -1},  {"C4", 1395, 8, 0, -1},
    {"C4", 1404, 8, 0, -1},  {"F3", 1422, 8, 0, -1},  {"C3", 1440, 8, 0, -1},
    {"E3", 1467, 8, 0, -1},  {"G3", 1494, 8, 0, -1},  {"C4", 1503, 8, 0, -1},
    {"G5", 1521, 8, 0, -1},  {"G5", 1539, 8, 0, -1},  {"G5", 1548, 8, 0, -1},
    {"G3", 1566, 8, 0, -1},  {"C3", 1584, 8, 0, -1},  {"G3", 1611, 8, 0, -1},
    {"C4", 1638, 8, 0, -1},  {"F3", 1656, 8, 0, -1},  {"C4", 1683, 8, 0, -1},
    {"C4", 1692, 8, 0, -1},  {"F3", 1710, 8, 0, -1},  {"C3", 1728, 8, 0, -1},
    {"G#3", 1746, 8, 0, -1}, {"A#3", 1773, 8, 0, -1}, {"C4", 1800, 8, 0, -1},
    {"G3", 1827, 8, 0, -1},  {"G3", 1836, 8, 0, -1},  {"C3", 1854, 8, 0, -1},
    {"G#2", 1872, 8, 0, -1}, {"D#3", 1899, 8, 0, -1}, {"G#3", 1926, 8, 0, -1},
    {"G3", 1944, 8, 0, -1},  {"C3", 1971, 8, 0, -1},  {"G2", 1998, 8, 0, -1},
    {"G#2", 2016, 8, 0, -1}, {"D#3", 2043, 8, 0, -1}, {"G#3", 2070, 8, 0, -1},
    {"G3", 2088, 8, 0, -1},  {"C3", 2115, 8, 0, -1},  {"G2", 2142, 8, 0, -1},
    {"G#2", 2160, 8, 0, -1}, {"D#3", 2187, 8, 0, -1}, {"G#3", 2214, 8, 0, -1},
    {"G3", 2232, 8, 0, -1},  {"C3", 2259, 8, 0, -1},  {"G2", 2286, 8, 0, -1},
    {"D3", 2304, 8, 0, -1},  {"D3", 2313, 8, 0, -1},  {"D3", 2331, 8, 0, -1},
    {"D3", 2349, 8, 0, -1},  {"D3", 2358, 8, 0, -1},  {"G4", 2376, 8, 0, -1},
    {"G3", 2412, 8, 0, -1},  {"G3", 2448, 8, 0, -1},  {"E3", 2475, 8, 0, -1},
    {"C3", 2502, 8, 0, -1},  {"F3", 2529, 8, 0, -1},  {"G3", 2547, 8, 0, -1},
    {"F#3", 2565, 8, 0, -1}, {"F3", 2574, 8, 0, -1},  {"E3", 2592, 8, 0, -1},
    {"C4", 2604, 8, 0, -1},  {"E4", 2616, 8, 0, -1},  {"F4", 2628, 8, 0, -1},
    {"D4", 2646, 8, 0, -1},  {"E4", 2655, 8, 0, -1},  {"C4", 2673, 8, 0, -1},
    {"A3", 2691, 8, 0, -1},  {"B3", 2700, 8, 0, -1},  {"G3", 2709, 8, 0, -1},
    {"G3", 2736, 8, 0, -1},  {"E3", 2763, 8, 0, -1},  {"C3", 2790, 8, 0, -1},
    {"F3", 2817, 8, 0, -1},  {"G3", 2835, 8, 0, -1},  {"F#3", 2853, 8, 0, -1},
    {"F3", 2862, 8, 0, -1},  {"E3", 2880, 8, 0, -1},  {"C4", 2892, 8, 0, -1},
    {"E4", 2904, 8, 0, -1},  {"F4", 2916, 8, 0, -1},  {"D4", 2934, 8, 0, -1},
    {"E4", 2943, 8, 0, -1},  {"C4", 2961, 8, 0, -1},  {"A3", 2979, 8, 0, -1},
    {"B3", 2988, 8, 0, -1},  {"G3", 2997, 8, 0, -1},  {"C3", 3024, 8, 0, -1},
    {"F#3", 3051, 8, 0, -1}, {"G3", 3060, 8, 0, -1},  {"C4", 3078, 8, 0, -1},
    {"F3", 3096, 8, 0, -1},  {"F3", 3114, 8, 0, -1},  {"C4", 3132, 8, 0, -1},
    {"C4", 3141, 8, 0, -1},  {"F3", 3150, 8, 0, -1},  {"D3", 3168, 8, 0, -1},
    {"F3", 3195, 8, 0, -1},  {"G3", 3204, 8, 0, -1},  {"B3", 3222, 8, 0, -1},
    {"G3", 3240, 8, 0, -1},  {"G3", 3258, 8, 0, -1},  {"C4", 3276, 8, 0, -1},
    {"C4", 3285, 8, 0, -1},  {"G3", 3294, 8, 0, -1},  {"C3", 3312, 8, 0, -1},
    {"F#3", 3339, 8, 0, -1}, {"G3", 3348, 8, 0, -1},  {"C4", 3366, 8, 0, -1},
    {"F3", 3384, 8, 0, -1},  {"F3", 3402, 8, 0, -1},  {"C4", 3420, 8, 0, -1},
    {"C4", 3429, 8, 0, -1},  {"F3", 3438, 8, 0, -1},  {"G3", 3456, 8, 0, -1},
    {"G3", 3483, 8, 0, -1},  {"G3", 3492, 8, 0, -1},  {"A3", 3504, 8, 0, -1},
    {"B3", 3516, 8, 0, -1},  {"C4", 3528, 8, 0, -1},  {"G3", 3546, 8, 0, -1},
    {"C3", 3564, 8, 0, -1},  {"C3", 3600, 8, 0, -1},  {"F#3", 3627, 8, 0, -1},
    {"G3", 3636, 8, 0, -1},  {"C4", 3654, 8, 0, -1},  {"F3", 3672, 8, 0, -1},
    {"F3", 3690, 8, 0, -1},  {"C4", 3708, 8, 0, -1},  {"C4", 3717, 8, 0, -1},
    {"F3", 3726, 8, 0, -1},  {"D3", 3744, 8, 0, -1},  {"F3", 3771, 8, 0, -1},
    {"G3", 3780, 8, 0, -1},  {"B3", 3798, 8, 0, -1},  {"G3", 3816, 8, 0, -1},
    {"G3", 3834, 8, 0, -1},  {"C4", 3852, 8, 0, -1},  {"C4", 3861, 8, 0, -1},
    {"G3", 3870, 8, 0, -1},  {"C3", 3888, 8, 0, -1},  {"F#3", 3915, 8, 0, -1},
    {"G3", 3924, 8, 0, -1},  {"C4", 3942, 8, 0, -1},  {"F3", 3960, 8, 0, -1},
    {"F3", 3978, 8, 0, -1},  {"C4", 3996, 8, 0, -1},  {"C4", 4005, 8, 0, -1},
    {"F3", 4014, 8, 0, -1},  {"G3", 4032, 8, 0, -1},  {"G3", 4059, 8, 0, -1},
    {"G3", 4068, 8, 0, -1},  {"A3", 4080, 8, 0, -1},  {"B3", 4092, 8, 0, -1},
    {"C4", 4104, 8, 0, -1},  {"G3", 4122, 8, 0, -1},  {"C3", 4140, 8, 0, -1},
    {"G#2", 4176, 8, 0, -1}, {"D#3", 4203, 8, 0, -1}, {"G#3", 4230, 8, 0, -1},
    {"G3", 4248, 8, 0, -1},  {"C3", 4275, 8, 0, -1},  {"G2", 4302, 8, 0, -1},
    {"G#2", 4320, 8, 0, -1}, {"D#3", 4347, 8, 0, -1}, {"G#3", 4374, 8, 0, -1},
    {"G3", 4392, 8, 0, -1},  {"C3", 4419, 8, 0, -1},  {"G2", 4446, 8, 0, -1},
    {"G#2", 4464, 8, 0, -1}, {"D#3", 4491, 8, 0, -1}, {"G#3", 4518, 8, 0, -1},
    {"G3", 4536, 8, 0, -1},  {"C3", 4563, 8, 0, -1},  {"G2", 4590, 8, 0, -1},
    {"D3", 4608, 8, 0, -1},  {"D3", 4617, 8, 0, -1},  {"D3", 4635, 8, 0, -1},
    {"D3", 4653, 8, 0, -1},  {"D3", 4662, 8, 0, -1},  {"G4", 4680, 8, 0, -1},
    {"G3", 4716, 8, 0, -1},  {"C3", 4752, 8, 0, -1},  {"F#3", 4779, 8, 0, -1},
    {"G3", 4788, 8, 0, -1},  {"C4", 4806, 8, 0, -1},  {"F3", 4824, 8, 0, -1},
    {"F3", 4842, 8, 0, -1},  {"C4", 4860, 8, 0, -1},  {"C4", 4869, 8, 0, -1},
    {"F3", 4878, 8, 0, -1},  {"D3", 4896, 8, 0, -1},  {"F3", 4923, 8, 0, -1},
    {"G3", 4932, 8, 0, -1},  {"B3", 4950, 8, 0, -1},  {"G3", 4968, 8, 0, -1},
    {"G3", 4986, 8, 0, -1},  {"C4", 5004, 8, 0, -1},  {"C4", 5013, 8, 0, -1},
    {"G3", 5022, 8, 0, -1},  {"C3", 5040, 8, 0, -1},  {"F#3", 5067, 8, 0, -1},
    {"G3", 5076, 8, 0, -1},  {"C4", 5094, 8, 0, -1},  {"F3", 5112, 8, 0, -1},
    {"F3", 5130, 8, 0, -1},  {"C4", 5148, 8, 0, -1},  {"C4", 5157, 8, 0, -1},
    {"F3", 5166, 8, 0, -1},  {"G3", 5184, 8, 0, -1},  {"G3", 5211, 8, 0, -1},
    {"G3", 5220, 8, 0, -1},  {"A3", 5232, 8, 0, -1},  {"B3", 5244, 8, 0, -1},
    {"C4", 5256, 8, 0, -1},  {"G3", 5274, 8, 0, -1},  {"C3", 5292, 8, 0, -1},
    {"G3", 5328, 8, 0, -1},  {"E3", 5355, 8, 0, -1},  {"C3", 5382, 8, 0, -1},
    {"F3", 5409, 8, 0, -1},  {"G3", 5427, 8, 0, -1},  {"F#3", 5445, 8, 0, -1},
    {"F3", 5454, 8, 0, -1},  {"E3", 5472, 8, 0, -1},  {"C4", 5484, 8, 0, -1},
    {"E4", 5496, 8, 0, -1},  {"F4", 5508, 8, 0, -1},  {"D4", 5526, 8, 0, -1},
    {"E4", 5535, 8, 0, -1},  {"C4", 5553, 8, 0, -1},  {"A3", 5571, 8, 0, -1},
    {"B3", 5580, 8, 0, -1},  {"G3", 5589, 8, 0, -1},  {"G3", 5616, 8, 0, -1},
    {"E3", 5643, 8, 0, -1},  {"C3", 5670, 8, 0, -1},  {"F3", 5697, 8, 0, -1},
    {"G3", 5715, 8, 0, -1},  {"F#3", 5733, 8, 0, -1}, {"F3", 5742, 8, 0, -1},
    {"E3", 5760, 8, 0, -1},  {"C4", 5772, 8, 0, -1},  {"E4", 5784, 8, 0, -1},
    {"F4", 5796, 8, 0, -1},  {"D4", 5814, 8, 0, -1},  {"E4", 5823, 8, 0, -1},
    {"C4", 5841, 8, 0, -1},  {"A3", 5859, 8, 0, -1},  {"B3", 5868, 8, 0, -1},
    {"G3", 5877, 8, 0, -1},  {"C3", 5904, 8, 0, -1},  {"G3", 5931, 8, 0, -1},
    {"C4", 5958, 8, 0, -1},  {"F3", 5976, 8, 0, -1},  {"C4", 6003, 8, 0, -1},
    {"C4", 6012, 8, 0, -1},  {"F3", 6030, 8, 0, -1},  {"C3", 6048, 8, 0, -1},
    {"E3", 6075, 8, 0, -1},  {"G3", 6102, 8, 0, -1},  {"C4", 6111, 8, 0, -1},
    {"G5", 6129, 8, 0, -1},  {"G5", 6147, 8, 0, -1},  {"G5", 6156, 8, 0, -1},
    {"G3", 6174, 8, 0, -1},  {"C3", 6192, 8, 0, -1},  {"G3", 6219, 8, 0, -1},
    {"C4", 6246, 8, 0, -1},  {"F3", 6264, 8, 0, -1},  {"C4", 6291, 8, 0, -1},
    {"C4", 6300, 8, 0, -1},  {"F3", 6318, 8, 0, -1},  {"C3", 6336, 8, 0, -1},
    {"G#3", 6354, 8, 0, -1}, {"A#3", 6381, 8, 0, -1}, {"C4", 6408, 8, 0, -1},
    {"G3", 6435, 8, 0, -1},  {"G3", 6444, 8, 0, -1},  {"C3", 6462, 8, 0, -1},
    {"C3", 6480, 8, 0, -1},  {"G3", 6507, 8, 0, -1},  {"C4", 6534, 8, 0, -1},
    {"F3", 6552, 8, 0, -1},  {"C4", 6579, 8, 0, -1},  {"C4", 6588, 8, 0, -1},
    {"F3", 6606, 8, 0, -1},  {"C3", 6624, 8, 0, -1},  {"E3", 6651, 8, 0, -1},
    {"G3", 6678, 8, 0, -1},  {"C4", 6687, 8, 0, -1},  {"G5", 6705, 8, 0, -1},
    {"G5", 6723, 8, 0, -1},  {"G5", 6732, 8, 0, -1},  {"G3", 6750, 8, 0, -1},
    {"C3", 6768, 8, 0, -1},  {"G3", 6795, 8, 0, -1},  {"C4", 6822, 8, 0, -1},
    {"F3", 6840, 8, 0, -1},  {"C4", 6867, 8, 0, -1},  {"C4", 6876, 8, 0, -1},
    {"F3", 6894, 8, 0, -1},  {"C3", 6912, 8, 0, -1},  {"G#3", 6930, 8, 0, -1},
    {"A#3", 6957, 8, 0, -1}, {"C4", 6984, 8, 0, -1},  {"G3", 7011, 8, 0, -1},
    {"G3", 7020, 8, 0, -1},  {"C3", 7038, 8, 0, -1},  {"G#2", 7056, 8, 0, -1},
    {"D#3", 7083, 8, 0, -1}, {"G#3", 7110, 8, 0, -1}, {"G3", 7128, 8, 0, -1},
    {"C3", 7155, 8, 0, -1},  {"G2", 7182, 8, 0, -1},
};
const size_t TRIANGLE_NOTES_LENGTH =
    sizeof(TRIANGLE_NOTES) / sizeof(TRIANGLE_NOTES[0]);
