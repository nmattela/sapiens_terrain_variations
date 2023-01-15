// MIT License
//
// Copyright(c) 2020 Jordan Peck (jordan.me2@gmail.com)
// Copyright(c) 2020 Contributors
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// .'',;:cldxkO00KKXXNNWWWNNXKOkxdollcc::::::;:::ccllloooolllllllllooollc:,'...        ...........',;cldxkO000Okxdlc::;;;,,;;;::cclllllll
// ..',;:ldxO0KXXNNNNNNNNXXK0kxdolcc::::::;;;,,,,,,;;;;;;;;;;:::cclllllc:;'....       ...........',;:ldxO0KXXXK0Okxdolc::;;;;::cllodddddo
// ...',:loxO0KXNNNNNXXKK0Okxdolc::;::::::::;;;,,'''''.....''',;:clllllc:;,'............''''''''',;:loxO0KXNNNNNXK0Okxdollccccllodxxxxxxd
// ....';:ldkO0KXXXKK00Okxdolcc:;;;;;::cclllcc:;;,''..... ....',;clooddolcc:;;;;,,;;;;;::::;;;;;;:cloxk0KXNWWWWWWNXKK0Okxddoooddxxkkkkkxx
// .....';:ldxkOOOOOkxxdolcc:;;;,,,;;:cllooooolcc:;'...      ..,:codxkkkxddooollloooooooollcc:::::clodkO0KXNWWWWWWNNXK00Okxxxxxxxxkkkkxxx
// . ....';:cloddddo___________,,,,;;:clooddddoolc:,...      ..,:ldx__00OOOkkk___kkkkkkxxdollc::::cclodkO0KXXNNNNNNXXK0OOkxxxxxxxxxxxxddd
// .......',;:cccc:|           |,,,;;:cclooddddoll:;'..     ..';cox|  \KKK000|   |KK00OOkxdocc___;::clldxxkO0KKKKK00Okkxdddddddddddddddoo
// .......'',,,,,''|   ________|',,;;::cclloooooolc:;'......___:ldk|   \KK000|   |XKKK0Okxolc|   |;;::cclodxxkkkkxxdoolllcclllooodddooooo
// ''......''''....|   |  ....'',,,,;;;::cclloooollc:;,''.'|   |oxk|    \OOO0|   |KKK00Oxdoll|___|;;;;;::ccllllllcc::;;,,;;;:cclloooooooo
// ;;,''.......... |   |_____',,;;;____:___cllo________.___|   |___|     \xkk|   |KK_______ool___:::;________;;;_______...'',;;:ccclllloo
// c:;,''......... |         |:::/     '   |lo/        |           |      \dx|   |0/       \d|   |cc/        |'/       \......',,;;:ccllo
// ol:;,'..........|    _____|ll/    __    |o/   ______|____    ___|   |   \o|   |/   ___   \|   |o/   ______|/   ___   \ .......'',;:clo
// dlc;,...........|   |::clooo|    /  |   |x\___   \KXKKK0|   |dol|   |\   \|   |   |   |   |   |d\___   \..|   |  /   /       ....',:cl
// xoc;'...  .....'|   |llodddd|    \__|   |_____\   \KKK0O|   |lc:|   |'\       |   |___|   |   |_____\   \.|   |_/___/...      ...',;:c
// dlc;'... ....',;|   |oddddddo\          |          |Okkx|   |::;|   |..\      |\         /|   |          | \         |...    ....',;:c
// ol:,'.......',:c|___|xxxddollc\_____,___|_________/ddoll|___|,,,|___|...\_____|:\ ______/l|___|_________/...\________|'........',;::cc
// c:;'.......';:codxxkkkkxxolc::;::clodxkOO0OOkkxdollc::;;,,''''',,,,''''''''''',,'''''',;:loxkkOOkxol:;,'''',,;:ccllcc:;,'''''',;::ccll
// ;,'.......',:codxkOO0OOkxdlc:;,,;;:cldxxkkxxdolc:;;,,''.....'',;;:::;;,,,'''''........,;cldkO0KK0Okdoc::;;::cloodddoolc:;;;;;::ccllooo
// .........',;:lodxOO0000Okdoc:,,',,;:clloddoolc:;,''.......'',;:clooollc:;;,,''.......',:ldkOKXNNXX0Oxdolllloddxxxxxxdolccccccllooodddd
// .    .....';:cldxkO0000Okxol:;,''',,;::cccc:;,,'.......'',;:cldxxkkxxdolc:;;,'.......';coxOKXNWWWNXKOkxddddxxkkkkkkxdoollllooddxxxxkkk
//       ....',;:codxkO000OOxdoc:;,''',,,;;;;,''.......',,;:clodkO00000Okxolc::;,,''..',;:ldxOKXNWWWNNK0OkkkkkkkkkkkxxddooooodxxkOOOOO000
//       ....',;;clodxkkOOOkkdolc:;,,,,,,,,'..........,;:clodxkO0KKXKK0Okxdolcc::;;,,,;;:codkO0XXNNNNXKK0OOOOOkkkkxxdoollloodxkO0KKKXXXXX
//
// VERSION: 1.0.1
// https://github.com/Auburn/FastNoise

// In *one* C or C++ file, use #define FNL_IMPL to generate implementation

#ifndef FASTNOISELITE_H
#define FASTNOISELITE_H

// Switch between using floats or doubles for input position
//typedef float FNLfloat;
typedef double FNLfloat;

#if defined(__cplusplus)
extern "C" {
#endif

#include <math.h>
#include <stdint.h>
#include <stdbool.h> 
#include <float.h>

// Enums
typedef enum
{
    FNL_NOISE_OPENSIMPLEX2,
    FNL_NOISE_OPENSIMPLEX2S,
    FNL_NOISE_CELLULAR,
    FNL_NOISE_PERLIN,
    FNL_NOISE_VALUE_CUBIC,
    FNL_NOISE_VALUE
} fnl_noise_type;

typedef enum
{
    FNL_ROTATION_NONE,
    FNL_ROTATION_IMPROVE_XY_PLANES,
    FNL_ROTATION_IMPROVE_XZ_PLANES
} fnl_rotation_type_3d;

typedef enum
{
    FNL_FRACTAL_NONE,
    FNL_FRACTAL_FBM,
    FNL_FRACTAL_RIDGED,
    FNL_FRACTAL_PINGPONG,
    FNL_FRACTAL_DOMAIN_WARP_PROGRESSIVE,
    FNL_FRACTAL_DOMAIN_WARP_INDEPENDENT
} fnl_fractal_type;

typedef enum
{
    FNL_CELLULAR_DISTANCE_EUCLIDEAN,
    FNL_CELLULAR_DISTANCE_EUCLIDEANSQ,
    FNL_CELLULAR_DISTANCE_MANHATTAN,
    FNL_CELLULAR_DISTANCE_HYBRID
} fnl_cellular_distance_func;

typedef enum
{
    FNL_CELLULAR_RETURN_VALUE_CELLVALUE,
    FNL_CELLULAR_RETURN_VALUE_DISTANCE,
    FNL_CELLULAR_RETURN_VALUE_DISTANCE2,
    FNL_CELLULAR_RETURN_VALUE_DISTANCE2ADD,
    FNL_CELLULAR_RETURN_VALUE_DISTANCE2SUB,
    FNL_CELLULAR_RETURN_VALUE_DISTANCE2MUL,
    FNL_CELLULAR_RETURN_VALUE_DISTANCE2DIV,
} fnl_cellular_return_type;

typedef enum
{
    FNL_DOMAIN_WARP_OPENSIMPLEX2,
    FNL_DOMAIN_WARP_OPENSIMPLEX2_REDUCED,
    FNL_DOMAIN_WARP_BASICGRID
} fnl_domain_warp_type;

/**
 * Structure containing entire noise system state.
 * @note Must only be created using fnlCreateState(optional: seed). To ensure defaults are set.
 */
typedef struct fnl_state
{
    /**
     * Seed used for all noise types.
     * @remark Default: 1337
     */
    int seed;

    /**
     * The frequency for all noise types.
     * @remark Default: 0.01
     */
    float frequency;

    /**
     * The noise algorithm to be used by GetNoise(...).
     * @remark Default: FNL_NOISE_OPENSIMPLEX2
     */
    fnl_noise_type noise_type;

    /**
     * Sets noise rotation type for 3D.
     * @remark Default: FNL_ROTATION_NONE
     */
    fnl_rotation_type_3d rotation_type_3d;

    /**
     * The method used for combining octaves for all fractal noise types.
     * @remark Default: None
     * @remark FNL_FRACTAL_DOMAIN_WARP_... only effects fnlDomainWarp...
     */
    fnl_fractal_type fractal_type;

    /**
     * The octave count for all fractal noise types.
     * @remark Default: 3
     */
    int octaves;

    /**
     * The octave lacunarity for all fractal noise types.
     * @remark Default: 2.0
     */
    float lacunarity;

    /**
     * The octave gain for all fractal noise types.
     * @remark Default: 0.5
     */
    float gain;

    /**
     * The octave weighting for all none Domaain Warp fractal types.
     * @remark Default: 0.0
     * @remark 
     */
    float weighted_strength;

    /**
     * The strength of the fractal ping pong effect.
     * @remark Default: 2.0
     */
    float ping_pong_strength;

    /**
     * The distance function used in cellular noise calculations.
     * @remark Default: FNL_CELLULAR_FUNC_DISTANCE
     */
    fnl_cellular_distance_func cellular_distance_func;

    /**
     * The cellular return type from cellular noise calculations.
     * @remark Default: FNL_CELLULAR_RETURN_VALUE_EUCLIEANSQ
     */
    fnl_cellular_return_type cellular_return_type;

    /**
     * The maximum distance a cellular point can move from it's grid position.
     * @remark Default: 1.0
     * @note Setting this higher than 1 will cause artifacts.
     */
    float cellular_jitter_mod;

    /**
     * The warp algorithm when using fnlDomainWarp...
     * @remark Default: OpenSimplex2
     */
    fnl_domain_warp_type domain_warp_type;

    /**
     * The maximum warp distance from original position when using fnlDomainWarp...
     * @remark Default: 1.0
     */
    float domain_warp_amp;
} fnl_state;

/**
 * Creates a noise state with default values.
 * @param seed Optionally set the state seed.
 */
fnl_state fnlCreateState();

/**
 * 2D noise at given position using the state settings
 * @returns Noise output bounded between -1 and 1.
 */
float fnlGetNoise2D(fnl_state *state, FNLfloat x, FNLfloat y);

/**
 * 3D noise at given position using the state settings
 * @returns Noise output bounded between -1 and 1.
 */
float fnlGetNoise3D(fnl_state *state, FNLfloat x, FNLfloat y, FNLfloat z);

/**
 * 2D warps the input position using current domain warp settings.
 * 
 * Example usage with fnlGetNoise2D:
 * ```
 * fnlDomainWarp2D(&state, &x, &y);
 * noise = fnlGetNoise2D(&state, x, y);
 * ```
 */
void fnlDomainWarp2D(fnl_state *state, FNLfloat *x, FNLfloat *y);

/**
 * 3D warps the input position using current domain warp settings.
 * 
 * Example usage with fnlGetNoise3D:
 * ```
 * fnlDomainWarp3D(&state, &x, &y, &z);
 * noise = fnlGetNoise3D(&state, x, y, z);
 * ```
 */
void fnlDomainWarp3D(fnl_state *state, FNLfloat *x, FNLfloat *y, FNLfloat *z);

// ====================
// Below this line is the implementation
// ====================

// //#if defined(FNL_IMPL)
// #ifndef FNL_IMPL
// #define FNL_IMPL



// #endif // FNL_IMPL

#if defined(__cplusplus)
}
#endif

#endif // FASTNOISELITE_H
