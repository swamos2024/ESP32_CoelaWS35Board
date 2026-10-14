#pragma once
#include <FastLED.h>
/*
*   This dependency is dedicated to converting given coordinates on Coela Cant's 
*   WS35 LED boards to return an index and pin (an address) for the FastLed library  
*   to edit. The grid will look like this:
*
*             (+y)     ____                                ____
*              ^      /.~. """",,,                  ,,,"""" .~.\
*              |      \  ,___    /                  \    ___,  /
*             y = 0    \________/  Right panel       \________/  left panel       
*                           (-x)  <----- x=0 ----->  (+x)
*   
*   x = 0, will be the gap between LED panels and so its not usable, to make it
*   match, y = 0 is also the not usable and represents the space just below the 
*   panels. This may however cause confusion since the matrixes holding the map
*   start indexing at 0.
*/

// this is the number of LEDs depending on the panel. (These functions currently only
// support whole panels, when the board perforation is not split)

#define BackPanelLEDCount 346
#define FrontPanelLEDCount 225
#define WholePanelLEDCount 571

/*
*    These define what pins output to the led boards. The index is only built to 
*    support when the boards are in one piece and the perforation is not split. 
*/

#define WS35LeftBackPin 38
#define WS35RightBackPin 36

/*
*   These structs will be used to encode the number pairs to define LEDs by coordinate,
*   and address.
*/

//coordinate of LED on face WS35 panels
struct LEDCoordinate {
    int x;
    int y;
};
        // number used in the LEDcoordinate struct to indicate nonexistant position
        #define COORDINATE_ERROR 0 


//Address of LED on face WS35 panels 
struct LEDAddress {
    CRGB* LEDstring;
    int index;
};
        // number used to represent nonexistant LED in LEDAddress
        #define NO_LED -1

        // number used to represent out of bound LED in LEDAddress
        #define OUTBOUND_LED -2


// Orders the CRGB structs of the two LED panels in a convenient way. There will only 
// be one of these used.
struct CRGBindexTEMPLATE {
    CRGB* LEDsLeftback;
    CRGB* LEDsRightback;
};

// this must be global VVVVVV. The full declaration is in the associated .ccp.

extern struct CRGBindexTEMPLATE CRGBindex;


/*
*   This is a map of LEDs coordinates to their index in the LED series. the dimensions 
*   are ordered so you can write them in x y order. -1 represents points with no LED,  
*   -1 = NO_LED. 
*
*   (Panel wired from back segment)
*/
int WS35Left_chain[34][23] = {
    { -1,  -1,  -1,  -1,  -1,  -1,  -1, 448, 449, 478, 479, 508, 509,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // row 0
    { -1,  -1,  -1,  -1,  -1, 419, 420, 447, 450, 477, 480, 507, 510, 537,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // row 1
    { -1,  -1,  -1, 392, 393, 418, 421, 446, 451, 476, 481, 506, 511, 536,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // row 2
    { -1, 367, 368, 391, 394, 417, 422, 445, 452, 475, 482, 505, 512, 535, 538,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // row 3
    {346, 366, 369, 390, 395, 416, 423, 444, 453, 474, 483, 504, 513, 534, 539,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // row 4
    {347, 365, 370, 389, 396, 415, 424, 443, 454, 473, 484, 503, 514, 533, 540,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // row 5
    {348, 364, 371, 388, 397, 414, 425, 442, 455, 472, 485, 502, 515, 532, 541, 558,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // row 6
    {349, 363, 372, 387, 398, 413, 426, 441, 456, 471, 486, 501, 516, 531, 542, 557,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // row 7
    {350, 362, 373, 386, 399, 412, 427, 440, 457, 470, 487, 500, 517, 530, 543, 556, 559,  -1,  -1,  -1,  -1,  -1,  -1}, // row 8
    {351, 361, 374, 385, 400, 411, 428, 439, 458, 469, 488, 499, 518, 529, 544, 555, 560,  -1,  -1,  -1,  -1,  -1,  -1}, // row 9
    {352, 360, 375, 384, 401, 410, 429, 438, 459, 468, 489, 498, 519, 528, 545, 554, 561,  -1,  -1,  -1,  -1,  -1,  -1}, // row 10
    {353, 359, 376, 383, 402, 409, 430, 437, 460, 467, 490, 497, 520, 527, 546, 553, 562, 569,  -1,  -1,  -1,  -1,  -1}, // row 11
    {354, 358, 377, 382, 403, 408, 431, 436, 461, 466, 491, 496, 521, 526, 547, 552, 563, 568,  -1,  -1,  -1,  -1,  -1}, // row 12
    {355, 357, 378, 381, 404, 407, 432, 435, 462, 465, 492, 495, 522, 525, 548, 551, 564, 567, 570,  -1,  -1,  -1,  -1}, // row 13
    { -1, 356, 379, 380, 405, 406, 433, 434, 463, 464, 493, 494, 523, 524, 549, 550, 565, 566,  -1,  -1,  -1,  -1,  -1}, // row 14
    
    { -1,  23,  24,  50,  51,  78,  79, 108, 109, 140, 141, 174, 175, 210, 211, 247, 248, 284, 285,  -1,  -1,  -1,  -1}, // row 15
    {  0,  22,  25,  49,  52,  77,  80, 107, 110, 139, 142, 173, 176, 209, 212, 246, 249, 283, 286, 318,  -1,  -1,  -1}, // row 16
    {  1,  21,  26,  48,  53,  76,  81, 106, 111, 138, 143, 172, 177, 208, 213, 245, 250, 282, 287, 317,  -1,  -1,  -1}, // row 17
    {  2,  20,  27,  47,  54,  75,  82, 105, 112, 137, 144, 171, 178, 207, 214, 244, 251, 281, 288, 316, 319,  -1,  -1}, // row 18
    {  3,  19,  28,  46,  55,  74,  83, 104, 113, 136, 145, 170, 179, 206, 215, 243, 252, 280, 289, 315, 320,  -1,  -1}, // row 19
    {  4,  18,  29,  45,  56,  73,  84, 103, 114, 135, 146, 169, 180, 205, 216, 242, 253, 279, 290, 314, 321,  -1,  -1}, // row 20
    {  5,  17,  30,  44,  57,  72,  85, 102, 115, 134, 147, 168, 181, 204, 217, 241, 254, 278, 291, 313, 322, 340,  -1}, // row 21
    {  6,  16,  31,  43,  58,  71,  86, 101, 116, 133, 148, 167, 182, 203, 218, 240, 255, 277, 292, 312, 323, 339,  -1}, // row 22
    {  7,  15,  32,  42,  59,  70,  87, 100, 117, 132, 149, 166, 183, 202, 219, 239, 256, 276, 293, 311, 324, 338,  -1}, // row 23
    {  8,  14,  33,  41,  60,  69,  88,  99, 118, 131, 150, 165, 184, 201, 220, 238, 257, 275, 294, 310, 325, 337, 341}, // row 24
    {  9,  13,  34,  40,  61,  68,  89,  98, 119, 130, 151, 164, 185, 200, 221, 237, 258, 274, 295, 309, 326, 336, 342}, // row 25
    { 10,  12,  35,  39,  62,  67,  90,  97, 120, 129, 152, 163, 186, 199, 222, 236, 259, 273, 296, 308, 327, 335, 343}, // row 26
    { -1,  11,  36,  38,  63,  66,  91,  96, 121, 128, 153, 162, 187, 198, 223, 235, 260, 272, 297, 307, 328, 334, 344}, // row 27
    { -1,  -1,  -1,  37,  64,  65,  92,  95, 122, 127, 154, 161, 188, 197, 224, 234, 261, 271, 298, 306, 329, 333, 345}, // row 28
    { -1,  -1,  -1,  -1,  -1,  -1,  93,  94, 123, 126, 155, 160, 189, 196, 225, 233, 262, 270, 299, 305, 330, 332,  -1}, // row 29
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 124, 125, 156, 159, 190, 195, 226, 232, 263, 269, 300, 304, 331,  -1,  -1}, // row 30
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 157, 158, 191, 194, 227, 231, 264, 268, 301, 303,  -1,  -1,  -1}, // row 31
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 192, 193, 228, 230, 265, 267, 302,  -1,  -1,  -1,  -1}, // row 32
    { -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 229, 266,  -1,  -1,  -1,  -1,  -1,  -1}, // row 33
};

//  Macro to make defining the CRGB structs Faster
#define LEDs_Struct_Init_Macro CRGB LEDsLeftBack[WholePanelLEDCount]; CRGB LEDsRightBack[WholePanelLEDCount] 

//  builds the CRGBindex struct. also preforms the FastLED.addLEDs usually done on startup.
void InitLEDsAndCRGBIndex (CRGB* LEDsLeftback, CRGB* LEDsRightBack);

//  This function takes in a coordinate and returns an led address
//  .pin = NO_LED indicates a grid space 
//  .pin = OUTBOUND_LED if you try to find an address off of the coordinate grid
//  when .pin = OUTBOUND_LED, .LEDstring = nullptr
LEDAddress FindAddress (LEDCoordinate Coordinate); 