/*
 * FIFO.h
 *
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


#ifndef FIFO_H_
#define FIFO_H_

#include "globals.h"

#define BUFFER_SIZE 64 // muss 2^n betragen (8, 16, 32, 64 ...)
#define BUFFER_MASK (BUFFER_SIZE-1) // Klammern auf keinen Fall vergessen

typedef struct FifoStruct
{
	  volatile uint8_t data[BUFFER_SIZE];
	  volatile uint8_t read; // zeigt auf das Feld mit dem �ltesten Inhalt
	  volatile uint8_t write; // zeigt immer auf leeres Feld
}Fifo;


void fifo_init(Fifo* fifo);

uint8_t fifo_bufferIn(Fifo* fifo, uint8_t byte);

uint8_t fifo_bufferOut(Fifo* fifo, uint8_t *pByte);

void fifo_clear(Fifo* fifo);


//--
#define BUFFER_SIZE_BIG 64 // muss 2^n betragen (8, 16, 32, 64 ...)
#define BUFFER_MASK_BIG (BUFFER_SIZE_BIG-1) // Klammern auf keinen Fall vergessen

typedef struct FifoStructBig
{
	volatile  uint8_t data[BUFFER_SIZE_BIG];
	volatile uint8_t read; // zeigt auf das Feld mit dem �ltesten Inhalt
	volatile uint8_t write; // zeigt immer auf leeres Feld
}FifoBig;


void fifoBig_init(FifoBig* fifo);

uint8_t fifoBig_bufferIn(FifoBig* fifo, uint8_t byte);

uint8_t fifoBig_bufferOut(FifoBig* fifo, uint8_t *pByte);

void fifoBig_clear(FifoBig* fifo);


#endif /* FIFO_H_ */
