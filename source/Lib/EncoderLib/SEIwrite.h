/* The copyright in this software is being made available under the BSD
 * License, included below. This software may be subject to other third party
 * and contributor rights, including patent rights, and no such rights are
 * granted under this license.
 *
 * Copyright (c) 2010-2021, ITU/ISO/IEC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  * Neither the name of the ITU/ISO/IEC nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#ifndef __SEIWRITE__
#define __SEIWRITE__

#include "VLCWriter.h"
#include "CommonLib/SEI.h"

class OutputBitstream;

//! \ingroup EncoderLib
//! \{
class SEIWriter : public VLCWriter
{
public:
  SEIWriter() {};
  virtual ~SEIWriter() {};

  void writeSEImessages(OutputBitstream& bs, const SEIMessages &seiList, HRD &hrd, bool isNested, const uint32_t temporalId);

protected:
  void xWriteSEIuserDataUnregistered(const SEIuserDataUnregistered &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIDecodingUnitInfo(const SEIDecodingUnitInfo &sei, const SEIBufferingPeriod &bp,
                                 const uint32_t temporalId, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIDecodedPictureHash(const SEIDecodedPictureHash &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIBufferingPeriod(const SEIBufferingPeriod &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIPictureTiming(const SEIPictureTiming &sei, const SEIBufferingPeriod &bp, const uint32_t temporalId,
                              int SEIPrefixIndicationIdx = 0);
  void xWriteSEIFrameFieldInfo(const SEIFrameFieldInfo &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIDependentRAPIndication(const SEIDependentRAPIndication &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIScalableNesting(OutputBitstream &bs, const SEIScalableNesting &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIFramePacking(const SEIFramePacking &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIParameterSetsInclusionIndication(const SEIParameterSetsInclusionIndication &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIMasteringDisplayColourVolume( const SEIMasteringDisplayColourVolume& sei, int SEIPrefixIndicationIdx = 0);
#if U0033_ALTERNATIVE_TRANSFER_CHARACTERISTICS_SEI
  void xWriteSEIAlternativeTransferCharacteristics(const SEIAlternativeTransferCharacteristics& sei, int SEIPrefixIndicationIdx = 0);
#endif
  void xWriteSEIEquirectangularProjection(const SEIEquirectangularProjection &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEISphereRotation(const SEISphereRotation &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIOmniViewport(const SEIOmniViewport &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIRegionWisePacking(const SEIRegionWisePacking &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIGeneralizedCubemapProjection(const SEIGeneralizedCubemapProjection &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEISubpictureLevelInfo(const SEISubpicureLevelInfo &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEISampleAspectRatioInfo(const SEISampleAspectRatioInfo &sei, int SEIPrefixIndicationIdx = 0);

  void xWriteSEIUserDataRegistered(const SEIUserDataRegistered &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIFilmGrainCharacteristics(const SEIFilmGrainCharacteristics &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIContentLightLevelInfo(const SEIContentLightLevelInfo &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIAmbientViewingEnvironment(const SEIAmbientViewingEnvironment &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIContentColourVolume(const SEIContentColourVolume &sei, int SEIPrefixIndicationIdx = 0);
#if SEI_MANIFEST_APP1 || SEI_APP3
  void xWriteSEIManifest(const SEIManifest &sei);
#endif
#if SEI_PREFIX_APP1 ||SEI_APP3
  void xWriteSEIPrefixIndication(OutputBitstream &bs, const SEIPrefixIndication &sei, HRD &hrd, const uint32_t temporalId);
  int  getUESENumBits(std::string str, int codeNum);
  void xWriteSPIByteAlign();
#endif 

  void xWriteSEIAnnotatedRegions(const SEIAnnotatedRegions &sei, int SEIPrefixIndicationIdx = 0);
  void xWriteSEIpayloadData(OutputBitstream &bs, const SEI& sei, HRD &hrd, const uint32_t temporalId, int SEIPrefixIndicationIdx = 0);
  void xWriteByteAlign();
protected:
  HRD m_nestingHrd;
};

//! \}

#endif
