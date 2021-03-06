// Copyright 2022 Stefan Kerkmann
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdbool.h>

extern void chSysHalt(const char *reason) __attribute__((noreturn));

void panic(const char *fmt, ...) {
    chSysHalt(fmt);
}

void hard_assertion_failure(void) {
    panic("hard assert");
}
