#ifndef JAVA_ACCESS_H
#define JAVA_ACCESS_H

#include "kerberos.h"

#define KERBEROS_PACKAGE "cz.zcu.connectors.kerberos"
#define KERBEROS_PACKAGE_PATH "cz/zcu/connectors/kerberos"

// keep in sync with KerberosPrincipal.java
#define SIGNATURE_KERBEROS_PRINCIPAL_INIT "(Ljava/lang/String;JJJLjava/lang/String;JILjava/lang/String;JJJJ)V"
// keep in sync with KerberosSearchResult.java
#define SIGNATURE_KERBEROS_SEARCH_RESULT_INIT "([L" KERBEROS_PACKAGE_PATH "/KerberosPrincipal;I)V"

jboolean jboolean_getter(JNIEnv *, jobject, const char*);
char* jstring_getter(JNIEnv *, jobject, const char*);
char* jguardedstring_getter(JNIEnv *, jobject, const char*, jclass);
krbconn_context_t* getContext(JNIEnv*, jobject);
int java_class(JNIEnv *env, jclass *clazz, const char *name);
int java_method(JNIEnv *env, jmethodID *mid, jclass clazz, const char *name, const char *signature);
void add_princ_to_array(JNIEnv*, jobjectArray, int, krbconn_principal_t, jclass);
jint throwException(JNIEnv*, const char *, const char*);

#endif
