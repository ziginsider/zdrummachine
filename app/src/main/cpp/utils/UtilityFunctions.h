/*
 * Copyright 2018 The Android Open Source Project
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

#ifndef ZDRUMMACHINE_UTILITYFUNCTIONS_H
#define ZDRUMMACHINE_UTILITYFUNCTIONS_H

#include <stdint.h>

constexpr int64_t kMillisecondsInSecond = 1000;
constexpr int64_t kNanosecondsInMillisecond = 1000000;
constexpr int64_t kFourSecondInMillisecond = 4000;

int64_t nowUptimeMillis();

constexpr int64_t convertFramesToMillis(const int64_t frames, const int sampleRate) {
    return static_cast<int64_t>((static_cast<double>(frames) / sampleRate) * kMillisecondsInSecond);
}

constexpr int64_t
convertFramesToMillisZ(const int64_t frames, const int sampleRate, const int multiplier) {
    int64_t offset = static_cast<int64_t>(multiplier * kFourSecondInMillisecond);
    return static_cast<int64_t>((static_cast<double>(frames) / sampleRate) * kMillisecondsInSecond +
                                offset);
}

#endif //ZDRUMMACHINE_UTILITYFUNCTIONS_H
