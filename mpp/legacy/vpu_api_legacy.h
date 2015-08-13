/*
 * Copyright 2010 Rockchip Electronics S.LSI Co. LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _VPU_API_H_
#define _VPU_API_H_

#include "vpu_api.h"

class VpuApi
{
public:
    VpuApi();
    ~VpuApi();

    RK_S32 init(VpuCodecContext *ctx, RK_U8 *extraData, RK_U32 extra_size);
    RK_S32 flush(VpuCodecContext *ctx);

    RK_S32 decode(VpuCodecContext *ctx, VideoPacket_t *pkt, DecoderOut_t *aDecOut);
    RK_S32 decode_sendstream(VpuCodecContext *ctx, VideoPacket_t *pkt);
    RK_S32 decode_getoutframe(VpuCodecContext *ctx, DecoderOut_t *aDecOut);
    RK_S32 preProcessPacket(VpuCodecContext *ctx, VideoPacket_t *pkt);

    RK_S32 encode(VpuCodecContext *ctx, EncInputStream_t *aEncInStrm, EncoderOut_t *aEncOut);
    RK_S32 encoder_sendframe(VpuCodecContext *ctx, EncInputStream_t *aEncInStrm);
    RK_S32 encoder_getstream(VpuCodecContext *ctx, EncoderOut_t *aEncOut);

    RK_S32 send_stream(RK_U8* buf,  RK_U32 size, RK_S64 timestamp, RK_S32 usePts);
    RK_S32 get_frame(DecoderOut_t *aDecOut);

    RK_S32 perform(RK_U32 cmd, RK_U32 *data);
    RK_S32 control(VpuCodecContext *ctx, VPU_API_CMD cmd, void *param);

};

#endif /*_VPU_API_H_*/

