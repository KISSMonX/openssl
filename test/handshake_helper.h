/*
 * Copyright 2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_HANDSHAKE_HELPER_H
#define HEADER_HANDSHAKE_HELPER_H

#include "ssl_test_ctx.h"

typedef struct handshake_result {
    ssl_test_result_t result;
    /* These alerts are in the 2-byte format returned by the info_callback. */
    /* Alert sent by the client; 0 if no alert. */
    int client_alert_sent;
    /* Alert received by the server; 0 if no alert. */
    int client_alert_received;
    /* Alert sent by the server; 0 if no alert. */
    int server_alert_sent;
    /* Alert received by the client; 0 if no alert. */
    int server_alert_received;
    /* Negotiated protocol. On success, these should always match. */
    int server_protocol;
    int client_protocol;
} HANDSHAKE_RESULT;

/* Do a handshake and report some information about the result. */
HANDSHAKE_RESULT do_handshake(SSL_CTX *server_ctx, SSL_CTX *client_ctx,
                              const SSL_TEST_CTX *test_ctx);

#endif  /* HEADER_HANDSHAKE_HELPER_H */
