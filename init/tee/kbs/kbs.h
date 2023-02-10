// SPDX-License-Identifier: Apache-2.0

#ifndef _KBS
#define _KBS

#include <curl/curl.h>
#include <openssl/evp.h>
#include <openssl/bn.h>

// kbs_util.c
char *tee_str(int);

/*
 * Identifiers for all possible TEE architectures.
 */
enum tee {
        TEE_SEV,
        TEE_SGX,
        TEE_SNP,
        TEE_TDX,
};

/*
 * The type of KBS operation to be performed.
 */
enum curl_post_type {
        KBS_CURL_REQ,
};

// kbs_types.c
int kbs_request_marshal(char *, int, char *);
int kbs_challenge(CURL *, char *, char *, char *);

// kbs_curl.c
int kbs_curl_post(CURL *, char *, char *, char *, int);

// kbs_crypto.c
int kbs_tee_pubkey_create(EVP_PKEY **, BIGNUM *, BIGNUM *);
int kbs_nonce_pubkey_hash(char *, EVP_PKEY *, unsigned char **, unsigned int *);

#endif /* _KBS */
