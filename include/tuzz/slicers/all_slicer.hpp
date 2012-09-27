#ifndef ALL_SLICER__HPP
#define ALL_SLICER__HPP
/**
 * Copyright (C) 2012 Anders Sundman <anders@4zm.org>
 *
 * This file is part of tuzz - the text fuzzer.
 *
 * tuzz is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * tuzz is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tuzz.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "tuzz/slicer.hpp"

namespace tuzz {

template <typename InIt>
struct all_slicer_base final : public tuzz::slicer_base<InIt> {
  virtual tuzz::chunks_base<InIt> slice(InIt first, InIt end) override;
};

using all_slicer = all_slicer_base<tuzz::slicer_base<>::input_iterator>;
}

#include "../src/slicers/all_slicer.cpp"

#endif
