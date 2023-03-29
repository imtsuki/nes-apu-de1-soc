#include "../audio.h"

const note_t TRIANGLE_NOTES[] = {
    {"A#2", 0, 6, 0, -1},    {"A#2", 24, 6, 0, -1},   {"A#2", 32, 6, 0, -1},
    {"A#2", 40, 6, 0, -1},   {"A#2", 48, 6, 0, -1},   {"A#2", 72, 6, 0, -1},
    {"A#2", 80, 6, 0, -1},   {"A#2", 88, 6, 0, -1},   {"G#2", 96, 6, 0, -1},
    {"G#2", 120, 6, 0, -1},  {"G#2", 128, 6, 0, -1},  {"G#2", 136, 6, 0, -1},
    {"G#2", 144, 6, 0, -1},  {"G#2", 168, 6, 0, -1},  {"G#2", 176, 6, 0, -1},
    {"G#2", 184, 6, 0, -1},  {"F#2", 192, 6, 0, -1},  {"F#2", 216, 6, 0, -1},
    {"F#2", 224, 6, 0, -1},  {"F#2", 232, 6, 0, -1},  {"F#2", 240, 6, 0, -1},
    {"F#2", 264, 6, 0, -1},  {"F#2", 272, 6, 0, -1},  {"F#2", 280, 6, 0, -1},
    {"F2", 288, 6, 0, -1},   {"F2", 312, 6, 0, -1},   {"F2", 336, 6, 0, -1},
    {"G2", 360, 6, 0, -1},   {"A2", 372, 6, 0, -1},   {"A#2", 384, 6, 0, -1},
    {"A#2", 408, 6, 0, -1},  {"A#2", 416, 6, 0, -1},  {"G#2", 424, 6, 0, -1},
    {"A#2", 432, 6, 0, -1},  {"A#2", 456, 6, 0, -1},  {"G#2", 480, 6, 0, -1},
    {"G#2", 504, 6, 0, -1},  {"G#2", 512, 6, 0, -1},  {"F#2", 520, 6, 0, -1},
    {"G#2", 528, 6, 0, -1},  {"G#2", 552, 6, 0, -1},  {"F#2", 576, 6, 0, -1},
    {"F#2", 600, 6, 0, -1},  {"F#2", 608, 6, 0, -1},  {"E2", 616, 6, 0, -1},
    {"F#2", 624, 6, 0, -1},  {"F#2", 648, 6, 0, -1},  {"C#3", 672, 6, 0, -1},
    {"C#3", 696, 6, 0, -1},  {"C#3", 704, 6, 0, -1},  {"C3", 712, 6, 0, -1},
    {"C#3", 720, 6, 0, -1},  {"C#3", 744, 6, 0, -1},  {"B2", 768, 6, 0, -1},
    {"B2", 792, 6, 0, -1},   {"B2", 800, 6, 0, -1},   {"A#2", 808, 6, 0, -1},
    {"B2", 816, 6, 0, -1},   {"B2", 840, 6, 0, -1},   {"B2", 848, 6, 0, -1},
    {"B2", 856, 6, 0, -1},   {"A#2", 864, 6, 0, -1},  {"A#2", 888, 6, 0, -1},
    {"A#2", 896, 6, 0, -1},  {"G#2", 904, 6, 0, -1},  {"A#2", 912, 6, 0, -1},
    {"A#2", 936, 6, 0, -1},  {"A#2", 944, 6, 0, -1},  {"A#2", 952, 6, 0, -1},
    {"C3", 960, 6, 0, -1},   {"C3", 984, 6, 0, -1},   {"C3", 992, 6, 0, -1},
    {"B2", 1000, 6, 0, -1},  {"C3", 1008, 6, 0, -1},  {"C3", 1032, 6, 0, -1},
    {"C3", 1040, 6, 0, -1},  {"C3", 1048, 6, 0, -1},  {"F2", 1056, 6, 0, -1},
    {"F2", 1080, 6, 0, -1},  {"F2", 1104, 6, 0, -1},  {"G2", 1128, 6, 0, -1},
    {"A2", 1140, 6, 0, -1},  {"A#2", 1152, 6, 0, -1}, {"A#2", 1176, 6, 0, -1},
    {"A#2", 1184, 6, 0, -1}, {"G#2", 1192, 6, 0, -1}, {"A#2", 1200, 6, 0, -1},
    {"A#2", 1224, 6, 0, -1}, {"G#2", 1248, 6, 0, -1}, {"G#2", 1272, 6, 0, -1},
    {"G#2", 1280, 6, 0, -1}, {"F#2", 1288, 6, 0, -1}, {"G#2", 1296, 6, 0, -1},
    {"G#2", 1320, 6, 0, -1}, {"F#2", 1344, 6, 0, -1}, {"F#2", 1368, 6, 0, -1},
    {"F#2", 1376, 6, 0, -1}, {"E2", 1384, 6, 0, -1},  {"F#2", 1392, 6, 0, -1},
    {"F#2", 1416, 6, 0, -1}, {"F2", 1440, 6, 0, -1},  {"F2", 1464, 6, 0, -1},
    {"F2", 1472, 6, 0, -1},  {"D#2", 1480, 6, 0, -1}, {"F2", 1488, 6, 0, -1},
    {"F2", 1512, 6, 0, -1},  {"E2", 1536, 6, 0, -1},  {"A#2", 1544, 6, 0, -1},
    {"C#3", 1552, 6, 0, -1}, {"E3", 1560, 6, 0, -1},  {"A#3", 1568, 6, 0, -1},
    {"C#4", 1576, 6, 0, -1}, {"E4", 1584, 6, 0, -1},  {"F4", 1632, 6, 0, -1},
    {"F2", 1656, 6, 0, -1},  {"F2", 1664, 6, 0, -1},  {"F2", 1672, 6, 0, -1},
    {"F2", 1680, 6, 0, -1},  {"E2", 1728, 6, 0, -1},  {"A#2", 1736, 6, 0, -1},
    {"C#3", 1744, 6, 0, -1}, {"E3", 1752, 6, 0, -1},  {"A#3", 1760, 6, 0, -1},
    {"C#4", 1768, 6, 0, -1}, {"E4", 1776, 6, 0, -1},  {"F4", 1824, 6, 0, -1},
    {"F2", 1848, 6, 0, -1},  {"F2", 1856, 6, 0, -1},  {"F2", 1864, 6, 0, -1},
    {"F2", 1872, 6, 0, -1},  {"B2", 1920, 6, 0, -1},  {"B2", 1944, 6, 0, -1},
    {"B2", 1952, 6, 0, -1},  {"A#2", 1960, 6, 0, -1}, {"B2", 1968, 6, 0, -1},
    {"B2", 1992, 6, 0, -1},  {"B2", 2000, 6, 0, -1},  {"B2", 2008, 6, 0, -1},
    {"A#2", 2016, 6, 0, -1}, {"A#2", 2040, 6, 0, -1}, {"A#2", 2048, 6, 0, -1},
    {"G#2", 2056, 6, 0, -1}, {"A#2", 2064, 6, 0, -1}, {"A#2", 2088, 6, 0, -1},
    {"A#2", 2096, 6, 0, -1}, {"A#2", 2104, 6, 0, -1}, {"C3", 2112, 6, 0, -1},
    {"C3", 2136, 6, 0, -1},  {"C3", 2144, 6, 0, -1},  {"B2", 2152, 6, 0, -1},
    {"C3", 2160, 6, 0, -1},  {"C3", 2184, 6, 0, -1},  {"C3", 2192, 6, 0, -1},
    {"C3", 2200, 6, 0, -1},  {"F2", 2208, 6, 0, -1},  {"F2", 2232, 6, 0, -1},
    {"F2", 2256, 6, 0, -1},  {"G2", 2280, 6, 0, -1},  {"A2", 2292, 6, 0, -1},
    {"A#2", 2304, 6, 0, -1}, {"A#2", 2328, 6, 0, -1}, {"A#2", 2336, 6, 0, -1},
    {"G#2", 2344, 6, 0, -1}, {"A#2", 2352, 6, 0, -1}, {"A#2", 2376, 6, 0, -1},
    {"G#2", 2400, 6, 0, -1}, {"G#2", 2424, 6, 0, -1}, {"G#2", 2432, 6, 0, -1},
    {"F#2", 2440, 6, 0, -1}, {"G#2", 2448, 6, 0, -1}, {"G#2", 2472, 6, 0, -1},
    {"F#2", 2496, 6, 0, -1}, {"F#2", 2520, 6, 0, -1}, {"F#2", 2528, 6, 0, -1},
    {"E2", 2536, 6, 0, -1},  {"F#2", 2544, 6, 0, -1}, {"F#2", 2568, 6, 0, -1},
    {"C#3", 2592, 6, 0, -1}, {"C#3", 2616, 6, 0, -1}, {"C#3", 2624, 6, 0, -1},
    {"C3", 2632, 6, 0, -1},  {"C#3", 2640, 6, 0, -1}, {"C#3", 2664, 6, 0, -1},
    {"B2", 2688, 6, 0, -1},  {"B2", 2712, 6, 0, -1},  {"B2", 2720, 6, 0, -1},
    {"A#2", 2728, 6, 0, -1}, {"B2", 2736, 6, 0, -1},  {"B2", 2760, 6, 0, -1},
    {"B2", 2768, 6, 0, -1},  {"B2", 2776, 6, 0, -1},  {"A#2", 2784, 6, 0, -1},
    {"A#2", 2808, 6, 0, -1}, {"A#2", 2816, 6, 0, -1}, {"G#2", 2824, 6, 0, -1},
    {"A#2", 2832, 6, 0, -1}, {"A#2", 2856, 6, 0, -1}, {"A#2", 2864, 6, 0, -1},
    {"A#2", 2872, 6, 0, -1}, {"C3", 2880, 6, 0, -1},  {"C3", 2904, 6, 0, -1},
    {"C3", 2912, 6, 0, -1},  {"B2", 2920, 6, 0, -1},  {"C3", 2928, 6, 0, -1},
    {"C3", 2952, 6, 0, -1},  {"C3", 2960, 6, 0, -1},  {"C3", 2968, 6, 0, -1},
    {"F2", 2976, 6, 0, -1},  {"F2", 3000, 6, 0, -1},  {"F2", 3024, 6, 0, -1},
    {"G2", 3048, 6, 0, -1},  {"A2", 3060, 6, 0, -1},  {"A#2", 3072, 6, 0, -1},
    {"A#2", 3096, 6, 0, -1}, {"A#2", 3104, 6, 0, -1}, {"G#2", 3112, 6, 0, -1},
    {"A#2", 3120, 6, 0, -1}, {"A#2", 3144, 6, 0, -1}, {"G#2", 3168, 6, 0, -1},
    {"G#2", 3192, 6, 0, -1}, {"G#2", 3200, 6, 0, -1}, {"F#2", 3208, 6, 0, -1},
    {"G#2", 3216, 6, 0, -1}, {"G#2", 3240, 6, 0, -1}, {"F#2", 3264, 6, 0, -1},
    {"F#2", 3288, 6, 0, -1}, {"F#2", 3296, 6, 0, -1}, {"E2", 3304, 6, 0, -1},
    {"F#2", 3312, 6, 0, -1}, {"F#2", 3336, 6, 0, -1}, {"F2", 3360, 6, 0, -1},
    {"F2", 3384, 6, 0, -1},  {"F2", 3392, 6, 0, -1},  {"D#2", 3400, 6, 0, -1},
    {"F2", 3408, 6, 0, -1},  {"F2", 3432, 6, 0, -1},  {"E2", 3456, 6, 0, -1},
    {"A#2", 3464, 6, 0, -1}, {"C#3", 3472, 6, 0, -1}, {"E3", 3480, 6, 0, -1},
    {"A#3", 3488, 6, 0, -1}, {"C#4", 3496, 6, 0, -1}, {"E4", 3504, 6, 0, -1},
    {"F4", 3552, 6, 0, -1},  {"F2", 3576, 6, 0, -1},  {"F2", 3584, 6, 0, -1},
    {"F2", 3592, 6, 0, -1},  {"F2", 3600, 6, 0, -1},  {"E2", 3648, 6, 0, -1},
    {"A#2", 3656, 6, 0, -1}, {"C#3", 3664, 6, 0, -1}, {"E3", 3672, 6, 0, -1},
    {"A#3", 3680, 6, 0, -1}, {"C#4", 3688, 6, 0, -1}, {"E4", 3696, 6, 0, -1},
    {"F4", 3744, 6, 0, -1},  {"F2", 3768, 6, 0, -1},  {"F2", 3776, 6, 0, -1},
    {"F2", 3784, 6, 0, -1},  {"F2", 3792, 6, 0, -1},  {"B2", 3840, 6, 0, -1},
    {"B2", 3864, 6, 0, -1},  {"B2", 3872, 6, 0, -1},  {"A#2", 3880, 6, 0, -1},
    {"B2", 3888, 6, 0, -1},  {"B2", 3912, 6, 0, -1},  {"B2", 3920, 6, 0, -1},
    {"B2", 3928, 6, 0, -1},  {"A#2", 3936, 6, 0, -1}, {"A#2", 3960, 6, 0, -1},
    {"A#2", 3968, 6, 0, -1}, {"G#2", 3976, 6, 0, -1}, {"A#2", 3984, 6, 0, -1},
    {"A#2", 4008, 6, 0, -1}, {"A#2", 4016, 6, 0, -1}, {"A#2", 4024, 6, 0, -1},
    {"C3", 4032, 6, 0, -1},  {"C3", 4056, 6, 0, -1},  {"C3", 4064, 6, 0, -1},
    {"B2", 4072, 6, 0, -1},  {"C3", 4080, 6, 0, -1},  {"C3", 4104, 6, 0, -1},
    {"C3", 4112, 6, 0, -1},  {"C3", 4120, 6, 0, -1},  {"F2", 4128, 6, 0, -1},
    {"F2", 4152, 6, 0, -1},  {"F2", 4176, 6, 0, -1},  {"G2", 4200, 6, 0, -1},
    {"A2", 4212, 6, 0, -1},  {"A#2", 4224, 6, 0, -1}, {"A#2", 4248, 6, 0, -1},
    {"A#2", 4256, 6, 0, -1}, {"G#2", 4264, 6, 0, -1}, {"A#2", 4272, 6, 0, -1},
    {"A#2", 4296, 6, 0, -1}, {"G#2", 4320, 6, 0, -1}, {"G#2", 4344, 6, 0, -1},
    {"G#2", 4352, 6, 0, -1}, {"F#2", 4360, 6, 0, -1}, {"G#2", 4368, 6, 0, -1},
    {"G#2", 4392, 6, 0, -1}, {"F#2", 4416, 6, 0, -1}, {"F#2", 4440, 6, 0, -1},
    {"F#2", 4448, 6, 0, -1}, {"E2", 4456, 6, 0, -1},  {"F#2", 4464, 6, 0, -1},
    {"F#2", 4488, 6, 0, -1}, {"C#3", 4512, 6, 0, -1}, {"C#3", 4536, 6, 0, -1},
    {"C#3", 4544, 6, 0, -1}, {"C3", 4552, 6, 0, -1},  {"C#3", 4560, 6, 0, -1},
    {"C#3", 4584, 6, 0, -1}, {"B2", 4608, 6, 0, -1},  {"B2", 4632, 6, 0, -1},
    {"B2", 4640, 6, 0, -1},  {"A#2", 4648, 6, 0, -1}, {"B2", 4656, 6, 0, -1},
    {"B2", 4680, 6, 0, -1},  {"B2", 4688, 6, 0, -1},  {"B2", 4696, 6, 0, -1},
    {"A#2", 4704, 6, 0, -1}, {"A#2", 4728, 6, 0, -1}, {"A#2", 4736, 6, 0, -1},
    {"G#2", 4744, 6, 0, -1}, {"A#2", 4752, 6, 0, -1}, {"A#2", 4776, 6, 0, -1},
    {"A#2", 4784, 6, 0, -1}, {"A#2", 4792, 6, 0, -1}, {"C3", 4800, 6, 0, -1},
    {"C3", 4824, 6, 0, -1},  {"C3", 4832, 6, 0, -1},  {"B2", 4840, 6, 0, -1},
    {"C3", 4848, 6, 0, -1},  {"C3", 4872, 6, 0, -1},  {"C3", 4880, 6, 0, -1},
    {"C3", 4888, 6, 0, -1},  {"F2", 4896, 6, 0, -1},  {"F2", 4920, 6, 0, -1},
    {"F2", 4944, 6, 0, -1},  {"G2", 4968, 6, 0, -1},  {"A2", 4980, 6, 0, -1},
    {"A#2", 4992, 6, 0, -1}, {"A#2", 5016, 6, 0, -1}, {"A#2", 5024, 6, 0, -1},
    {"G#2", 5032, 6, 0, -1}, {"A#2", 5040, 6, 0, -1}, {"A#2", 5064, 6, 0, -1},
    {"G#2", 5088, 6, 0, -1}, {"G#2", 5112, 6, 0, -1}, {"G#2", 5120, 6, 0, -1},
    {"F#2", 5128, 6, 0, -1}, {"G#2", 5136, 6, 0, -1}, {"G#2", 5160, 6, 0, -1},
    {"F#2", 5184, 6, 0, -1}, {"F#2", 5208, 6, 0, -1}, {"F#2", 5216, 6, 0, -1},
    {"E2", 5224, 6, 0, -1},  {"F#2", 5232, 6, 0, -1}, {"F#2", 5256, 6, 0, -1},
    {"F2", 5280, 6, 0, -1},  {"F2", 5304, 6, 0, -1},  {"F2", 5312, 6, 0, -1},
    {"D#2", 5320, 6, 0, -1}, {"F2", 5328, 6, 0, -1},  {"F2", 5352, 6, 0, -1},
    {"E2", 5376, 6, 0, -1},  {"A#2", 5384, 6, 0, -1}, {"C#3", 5392, 6, 0, -1},
    {"E3", 5400, 6, 0, -1},  {"A#3", 5408, 6, 0, -1}, {"C#4", 5416, 6, 0, -1},
    {"E4", 5424, 6, 0, -1},  {"F4", 5472, 6, 0, -1},  {"F2", 5496, 6, 0, -1},
    {"F2", 5504, 6, 0, -1},  {"F2", 5512, 6, 0, -1},  {"F2", 5520, 6, 0, -1},
    {"E2", 5568, 6, 0, -1},  {"A#2", 5576, 6, 0, -1}, {"C#3", 5584, 6, 0, -1},
    {"E3", 5592, 6, 0, -1},  {"A#3", 5600, 6, 0, -1}, {"C#4", 5608, 6, 0, -1},
    {"E4", 5616, 6, 0, -1},  {"F4", 5664, 6, 0, -1},  {"F2", 5688, 6, 0, -1},
    {"F2", 5696, 6, 0, -1},  {"F2", 5704, 6, 0, -1},  {"F2", 5712, 6, 0, -1},
    {"B2", 5760, 6, 0, -1},  {"B2", 5784, 6, 0, -1},  {"B2", 5792, 6, 0, -1},
    {"A#2", 5800, 6, 0, -1}, {"B2", 5808, 6, 0, -1},  {"B2", 5832, 6, 0, -1},
    {"B2", 5840, 6, 0, -1},  {"B2", 5848, 6, 0, -1},  {"A#2", 5856, 6, 0, -1},
    {"A#2", 5880, 6, 0, -1}, {"A#2", 5888, 6, 0, -1}, {"G#2", 5896, 6, 0, -1},
    {"A#2", 5904, 6, 0, -1}, {"A#2", 5928, 6, 0, -1}, {"A#2", 5936, 6, 0, -1},
    {"A#2", 5944, 6, 0, -1}, {"C3", 5952, 6, 0, -1},  {"C3", 5976, 6, 0, -1},
    {"C3", 5984, 6, 0, -1},  {"B2", 5992, 6, 0, -1},  {"C3", 6000, 6, 0, -1},
    {"C3", 6024, 6, 0, -1},  {"C3", 6032, 6, 0, -1},  {"C3", 6040, 6, 0, -1},
    {"F2", 6048, 6, 0, -1},  {"F2", 6072, 6, 0, -1},  {"F2", 6096, 6, 0, -1},
    {"G2", 6120, 6, 0, -1},  {"A2", 6132, 6, 0, -1},  {"A#2", 6144, 6, 0, -1},
    {"A#2", 6168, 6, 0, -1}, {"A#2", 6176, 6, 0, -1}, {"G#2", 6184, 6, 0, -1},
    {"A#2", 6192, 6, 0, -1}, {"A#2", 6216, 6, 0, -1}, {"G#2", 6240, 6, 0, -1},
    {"G#2", 6264, 6, 0, -1}, {"G#2", 6272, 6, 0, -1}, {"F#2", 6280, 6, 0, -1},
    {"G#2", 6288, 6, 0, -1}, {"G#2", 6312, 6, 0, -1}, {"F#2", 6336, 6, 0, -1},
    {"F#2", 6360, 6, 0, -1}, {"F#2", 6368, 6, 0, -1}, {"E2", 6376, 6, 0, -1},
    {"F#2", 6384, 6, 0, -1}, {"F#2", 6408, 6, 0, -1}, {"C#3", 6432, 6, 0, -1},
    {"C#3", 6456, 6, 0, -1}, {"C#3", 6464, 6, 0, -1}, {"C3", 6472, 6, 0, -1},
    {"C#3", 6480, 6, 0, -1}, {"C#3", 6504, 6, 0, -1}, {"B2", 6528, 6, 0, -1},
    {"B2", 6552, 6, 0, -1},  {"B2", 6560, 6, 0, -1},  {"A#2", 6568, 6, 0, -1},
    {"B2", 6576, 6, 0, -1},  {"B2", 6600, 6, 0, -1},  {"B2", 6608, 6, 0, -1},
    {"B2", 6616, 6, 0, -1},  {"A#2", 6624, 6, 0, -1}, {"A#2", 6648, 6, 0, -1},
    {"A#2", 6656, 6, 0, -1}, {"G#2", 6664, 6, 0, -1}, {"A#2", 6672, 6, 0, -1},
    {"A#2", 6696, 6, 0, -1}, {"A#2", 6704, 6, 0, -1}, {"A#2", 6712, 6, 0, -1},
    {"C3", 6720, 6, 0, -1},  {"C3", 6744, 6, 0, -1},  {"C3", 6752, 6, 0, -1},
    {"B2", 6760, 6, 0, -1},  {"C3", 6768, 6, 0, -1},  {"C3", 6792, 6, 0, -1},
    {"C3", 6800, 6, 0, -1},  {"C3", 6808, 6, 0, -1},  {"F2", 6816, 6, 0, -1},
    {"F2", 6840, 6, 0, -1},  {"F2", 6864, 6, 0, -1},  {"G2", 6888, 6, 0, -1},
    {"A2", 6900, 6, 0, -1},  {"A#2", 6912, 6, 0, -1}, {"A#2", 6936, 6, 0, -1},
    {"A#2", 6944, 6, 0, -1}, {"G#2", 6952, 6, 0, -1}, {"A#2", 6960, 6, 0, -1},
    {"A#2", 6984, 6, 0, -1}, {"G#2", 7008, 6, 0, -1}, {"G#2", 7032, 6, 0, -1},
    {"G#2", 7040, 6, 0, -1}, {"F#2", 7048, 6, 0, -1}, {"G#2", 7056, 6, 0, -1},
    {"G#2", 7080, 6, 0, -1}, {"F#2", 7104, 6, 0, -1}, {"F#2", 7128, 6, 0, -1},
    {"F#2", 7136, 6, 0, -1}, {"E2", 7144, 6, 0, -1},  {"F#2", 7152, 6, 0, -1},
    {"F#2", 7176, 6, 0, -1},
};

const size_t TRIANGLE_NOTES_LENGTH =
    sizeof(TRIANGLE_NOTES) / sizeof(TRIANGLE_NOTES[0]);
