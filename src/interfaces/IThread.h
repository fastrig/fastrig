/* XTLRig
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2016-2018 XTLRig       <support@xtlrig.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __ITHREAD_H__
#define __ITHREAD_H__


#include <stdint.h>


#include "common/xtlrig.h"
#include "rapidjson/fwd.h"


namespace xtlrig {


class IThread
{
public:
    enum Type {
        CPU,
        OpenCL,
        CUDA
    };

    enum Multiway {
        SingleWay = 1,
        DoubleWay,
        TripleWay,
        QuadWay,
        PentaWay
    };

    virtual ~IThread() {}

    virtual Algo algorithm() const                                    = 0;
    virtual int priority() const                                      = 0;
    virtual int64_t affinity() const                                  = 0;
    virtual Multiway multiway() const                                 = 0;
    virtual rapidjson::Value toConfig(rapidjson::Document &doc) const = 0;
    virtual size_t index() const                                      = 0;
    virtual Type type() const                                         = 0;

#   ifndef XMRIG_NO_API
    virtual rapidjson::Value toAPI(rapidjson::Document &doc) const = 0;
#   endif
};


} /* namespace xtlrig */


#endif // __ITHREAD_H__
