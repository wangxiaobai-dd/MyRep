
#ifndef NF_TUTORIAL1_H
#define NF_TUTORIAL1_H

#define NF_EXPORT extern "C" __attribute ((visibility("default")))

class User;
NF_EXPORT void test(User* user);

#endif
