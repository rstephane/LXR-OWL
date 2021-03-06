/*
 * distortion.h
 *
 *  Created on: 11.04.2012
 * ------------------------------------------------------------------------------------------------------------------------
 *  Copyright 2013 Julian Schmidt
 *  Julian@sonic-potions.com
 * ------------------------------------------------------------------------------------------------------------------------
 *  This file is part of the Sonic Potions LXR drumsynth firmware.
 * ------------------------------------------------------------------------------------------------------------------------
 *  Redistribution and use of the LXR code or any derivative works are permitted
 *  provided that the following conditions are met:
 *
 *       - The code may not be sold, nor may it be used in a commercial product or activity.
 *
 *       - Redistributions that are modified from the original source must include the complete
 *         source code, including the source code for all components used by a binary built
 *         from the modified sources. However, as a special exception, the source code distributed
 *         need not include anything that is normally distributed (in either source or binary form)
 *         with the major components (compiler, kernel, and so on) of the operating system on which
 *         the executable runs, unless that component itself accompanies the executable.
 *
 *       - Redistributions must reproduce the above copyright notice, this list of conditions and the
 *         following disclaimer in the documentation and/or other materials provided with the distribution.
 * ------------------------------------------------------------------------------------------------------------------------
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 *   USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ------------------------------------------------------------------------------------------------------------------------
 */


#ifndef DISTORTION_H_
#define DISTORTION_H_
//--------------------------------------------------
#include "stm32f4xx.h"
#include "config.h"
//--------------------------------------------------
typedef struct DistStruct
{
	float shape;
	float inv_shape;
}Distortion;
//--------------------------------------------------
void setDistortionShape(Distortion *dist, uint8_t shape);
//--------------------------------------------------
void calcDistBlock(const Distortion *dist, int16_t* buf, const uint8_t size);
//--------------------------------------------------
float distortion_calcSampleFloat(const Distortion *dist, float x);
//--------------------------------------------------


// -------------------------------
// rstephane

float calcRange(uint8_t valueAmount, float old_min ,float old_max,float new_min,float new_max );
void calcFxBlock(uint8_t maskType, int16_t* buf,const uint8_t size, uint8_t fx1, uint8_t fx2, uint8_t fx3);
void calcParamEqBlock(int16_t* buf,const uint8_t size, uint8_t fx4, uint8_t fx5, uint8_t fx6,uint8_t fx7);
void BassBoost(int16_t* buf,const uint8_t size, float selectivity, float gain1,float gain2,float ratio ,float cap);
float calcCompressionBlock(int16_t* buf,const uint8_t size, int8_t threshold,uint8_t ratio,float attack_constant,float release_constant,float penv);
void calcRingModulatorBlock(int16_t* buf, uint8_t size, double modulatorFrequency, double carrierFrequency,double modulatorAngle);
void calcLofiBlock(int16_t* buf, uint8_t size, float normfreq, uint8_t bits );
float decimate(float x, int bits, float rate);
float decimateAdv(float x, int bits, float rate);
uint16_t reverseBits(uint16_t num);
#endif /* DISTORTION_H_ */
