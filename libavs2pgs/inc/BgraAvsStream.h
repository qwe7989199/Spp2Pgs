/*----------------------------------------------------------------------------
* avs2pgs - Generates BluRay PG Stream from RGBA AviSynth scripts
* by Giton Xu <adm@subelf.net>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*----------------------------------------------------------------------------*/

#pragma once

#include <Windows.h>
#include <tchar.h>
#include <Vfw.h>

#include "GraphicalTypes.h"
#include "A2PExceptions.h"
#include "FrameStream.h"

namespace avs2pgs
{

	class BgraAvsStream :
		public FrameStream
	{
	public:
		BgraAvsStream(TCHAR* avspath, FrameStreamAdvisor const * advisor) throw(A2PException);
		~BgraAvsStream();

		int GetNextFrame(StillImage *image);

		inline int GetFrameCount() const  { return this->frameCount; }
		inline int GetCurrentIndex() const  { return this->index; }
		inline Size GetFrameSize() const  { return this->frameSize; }
		inline BdViFrameRate GetFrameRate() const  { return this->frameRate; }
		inline FrameStreamAdvisor const * GetAdvisor() const { return this->advisor; }

	private:
		int index;
		int frameCount;
		Size frameSize;
		BdViFrameRate frameRate;

		PAVISTREAM stream;
		FrameStreamAdvisor const * advisor;

		void OpenAvsFile(TCHAR* avspath) throw(A2PException);
		void CloseAvsFile();
	};

}