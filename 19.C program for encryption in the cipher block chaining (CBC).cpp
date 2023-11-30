{"payload":{"allShortcutsEnabled":true,"fileTree":{"":{"items":[{"name":"1.ceaser cipher.cpp","path":"1.ceaser cipher.cpp","contentType":"file"},{"name":"10.play fair cipher (doubt).cpp","path":"10.play fair cipher (doubt).cpp","contentType":"file"},{"name":"11.play fair cipher possible keys.cpp","path":"11.play fair cipher possible keys.cpp","contentType":"file"},{"name":"12.hill cipher.cpp","path":"12.hill cipher.cpp","contentType":"file"},{"name":"13.hill cipher.cpp","path":"13.hill cipher.cpp","contentType":"file"},{"name":"14.Vigenère cipher.cpp","path":"14.Vigenère cipher.cpp","contentType":"file"},{"name":"15.letter frequency attack(doubt).cpp","path":"15.letter frequency attack(doubt).cpp","contentType":"file"},{"name":"16.letter frequency attack monoalphabetic substition(doubt).cpp","path":"16.letter frequency attack monoalphabetic substition(doubt).cpp","contentType":"file"},{"name":"17.DES.cpp","path":"17.DES.cpp","contentType":"file"},{"name":"18.DES.cpp","path":"18.DES.cpp","contentType":"file"},{"name":"19.C program for encryption in the cipher block chaining (CBC).cpp","path":"19.C program for encryption in the cipher block chaining (CBC).cpp","contentType":"file"},{"name":"2.mono alphabetic.cpp","path":"2.mono alphabetic.cpp","contentType":"file"},{"name":"20.ECB Mode.cpp","path":"20.ECB Mode.cpp","contentType":"file"},{"name":"21 encrypt vigenere cipher.c","path":"21 encrypt vigenere cipher.c","contentType":"file"},{"name":"22 aditive cipher Latest.c","path":"22 aditive cipher Latest.c","contentType":"file"},{"name":"23 Ecb mode.c","path":"23 Ecb mode.c","contentType":"file"},{"name":"24 des for security.c","path":"24 des for security.c","contentType":"file"},{"name":"25 enc&dec cipher block.c","path":"25 enc&dec cipher block.c","contentType":"file"},{"name":"26 RSA .c","path":"26 RSA .c","contentType":"file"},{"name":"27 RSA for public key.c","path":"27 RSA for public key.c","contentType":"file"},{"name":"28 RSA for private key.c","path":"28 RSA for private key.c","contentType":"file"},{"name":"29 RSA cryptosystem.c","path":"29 RSA cryptosystem.c","contentType":"file"},{"name":"3.play fair.cpp","path":"3.play fair.cpp","contentType":"file"},{"name":"30 diffie hellman protocol.c","path":"30 diffie hellman protocol.c","contentType":"file"},{"name":"31 SHA-3.c","path":"31 SHA-3.c","contentType":"file"},{"name":"32 CBC MAC.c","path":"32 CBC MAC.c","contentType":"file"},{"name":"33 CMAC.c","path":"33 CMAC.c","contentType":"file"},{"name":"34 dsa &rsa signature.c","path":"34 dsa &rsa signature.c","contentType":"file"},{"name":"35 DES.c","path":"35 DES.c","contentType":"file"},{"name":"36 ecb cbc.c","path":"36 ecb cbc.c","contentType":"file"},{"name":"37 ceaser & vigenere.c","path":"37 ceaser & vigenere.c","contentType":"file"},{"name":"38 Hill cipher succumbs.c","path":"38 Hill cipher succumbs.c","contentType":"file"},{"name":"4.POLYALPHABETIC.cpp","path":"4.POLYALPHABETIC.cpp","contentType":"file"},{"name":"40 frequency attack monoalphabetic.c","path":"40 frequency attack monoalphabetic.c","contentType":"file"},{"name":"5.affine cipher.cpp","path":"5.affine cipher.cpp","contentType":"file"},{"name":"6.affine cipher.cpp","path":"6.affine cipher.cpp","contentType":"file"},{"name":"8.monoalphabetic.cpp","path":"8.monoalphabetic.cpp","contentType":"file"},{"name":"9.PT-109 American patrol boat.cpp","path":"9.PT-109 American patrol boat.cpp","contentType":"file"}],"totalCount":38}},"fileTreeProcessingTime":6.132356000000001,"foldersToFetch":[],"reducedMotionEnabled":"system","repo":{"id":720360408,"defaultBranch":"main","name":"cryptography-and-network-security","ownerLogin":"192110488","currentUserCanPush":false,"isFork":false,"isEmpty":false,"createdAt":"2023-11-18T14:06:21.000+05:30","ownerAvatar":"https://avatars.githubusercontent.com/u/112234427?v=4","public":true,"private":false,"isOrgOwned":false},"symbolsExpanded":false,"treeExpanded":true,"refInfo":{"name":"main","listCacheKey":"v0:1700724303.0","canEdit":true,"refType":"branch","currentOid":"c980d3cbfb655bfb03f62c79270f87b4411f084f"},"path":"19.C program for encryption in the cipher block chaining (CBC).cpp","currentUser":{"id":132535950,"login":"lokeshbabu9876","userEmail":"loki143mangamuri@gmail.com"},"blob":{"rawLines":["#include <stdio.h>\r","#include <stdlib.h>\r","#include <string.h>\r","#include <openssl.h>\r","\r","void print_hex(const char *label, const unsigned char *data, size_t len) {\r","    printf(\"%s: \", label);\r","    for (size_t i = 0; i < len; ++i) {\r","        printf(\"%02X \", data[i]);\r","    }\r","    printf(\"\\n\");\r","}\r","\r","void encrypt_cbc_3des(const unsigned char *plaintext, const unsigned char *key, const unsigned char *iv, size_t plaintext_len) {\r","    DES_cblock des_key1, des_key2, des_key3;\r","    DES_key_schedule ks1, ks2, ks3;\r","\r","    // Split the 24-byte key into three separate 8-byte DES keys\r","    memcpy(des_key1, key, 8);\r","    memcpy(des_key2, key + 8, 8);\r","    memcpy(des_key3, key + 16, 8);\r","\r","    DES_set_key(&des_key1, &ks1);\r","    DES_set_key(&des_key2, &ks2);\r","    DES_set_key(&des_key3, &ks3);\r","\r","    DES_cblock ivec;\r","    memcpy(ivec, iv, sizeof(ivec));\r","\r","    // Perform encryption\r","    size_t block_size = DES_BLOCK_SIZE;\r","    unsigned char* encrypted_data = (unsigned char*)malloc(plaintext_len);\r","    DES_ede3_cbc_encrypt(plaintext, encrypted_data, plaintext_len, &ks1, &ks2, &ks3, &ivec, DES_ENCRYPT);\r","\r","    print_hex(\"Encrypted data\", encrypted_data, plaintext_len);\r","\r","    free(encrypted_data);\r","}\r","\r","int main() {\r","    const unsigned char plaintext[] = \"Hello, CBC 3DES Encryption!\";\r","    const unsigned char key[] = \"sOmE_KeY_For_3DES_Encryption\";\r","    const unsigned char iv[] = \"IV_IV_IV\"; // Initialization Vector\r","\r","    printf(\"Plaintext: %s\\n\", plaintext);\r","\r","    size_t plaintext_len = strlen((const char *)plaintext);\r","\r","    printf(\"Plaintext Length: %zu\\n\", plaintext_len);\r","\r","    encrypt_cbc_3des(plaintext, key, iv, plaintext_len);\r","\r","    return 0;\r","}\r","\r"],"stylingDirectives":[[{"start":1,"end":8,"cssClass":"pl-k"},{"start":9,"end":18,"cssClass":"pl-s"},{"start":9,"end":10,"cssClass":"pl-pds"},{"start":17,"end":18,"cssClass":"pl-pds"}],[{"start":1,"end":8,"cssClass":"pl-k"},{"start":9,"end":19,"cssClass":"pl-s"},{"start":9,"end":10,"cssClass":"pl-pds"},{"start":18,"end":19,"cssClass":"pl-pds"}],[{"start":1,"end":8,"cssClass":"pl-k"},{"start":9,"end":19,"cssClass":"pl-s"},{"start":9,"end":10,"cssClass":"pl-pds"},{"start":18,"end":19,"cssClass":"pl-pds"}],[{"start":1,"end":8,"cssClass":"pl-k"},{"start":9,"end":20,"cssClass":"pl-s"},{"start":9,"end":10,"cssClass":"pl-pds"},{"start":19,"end":20,"cssClass":"pl-pds"}],[],[{"start":0,"end":4,"cssClass":"pl-k"},{"start":5,"end":14,"cssClass":"pl-en"},{"start":15,"end":20,"cssClass":"pl-k"},{"start":21,"end":25,"cssClass":"pl-k"},{"start":34,"end":39,"cssClass":"pl-k"},{"start":40,"end":48,"cssClass":"pl-k"},{"start":49,"end":53,"cssClass":"pl-k"},{"start":61,"end":67,"cssClass":"pl-c1"}],[{"start":4,"end":10,"cssClass":"pl-c1"},{"start":11,"end":17,"cssClass":"pl-s"},{"start":11,"end":12,"cssClass":"pl-pds"},{"start":16,"end":17,"cssClass":"pl-pds"}],[{"start":4,"end":7,"cssClass":"pl-k"},{"start":9,"end":15,"cssClass":"pl-c1"},{"start":20,"end":21,"cssClass":"pl-c1"}],[{"start":8,"end":14,"cssClass":"pl-c1"},{"start":15,"end":22,"cssClass":"pl-s"},{"start":15,"end":16,"cssClass":"pl-pds"},{"start":21,"end":22,"cssClass":"pl-pds"}],[],[{"start":4,"end":10,"cssClass":"pl-c1"},{"start":11,"end":15,"cssClass":"pl-s"},{"start":11,"end":12,"cssClass":"pl-pds"},{"start":12,"end":14,"cssClass":"pl-cce"},{"start":14,"end":15,"cssClass":"pl-pds"}],[],[],[{"start":0,"end":4,"cssClass":"pl-k"},{"start":5,"end":21,"cssClass":"pl-en"},{"start":22,"end":27,"cssClass":"pl-k"},{"start":28,"end":36,"cssClass":"pl-k"},{"start":37,"end":41,"cssClass":"pl-k"},{"start":54,"end":59,"cssClass":"pl-k"},{"start":60,"end":68,"cssClass":"pl-k"},{"start":69,"end":73,"cssClass":"pl-k"},{"start":80,"end":85,"cssClass":"pl-k"},{"start":86,"end":94,"cssClass":"pl-k"},{"start":95,"end":99,"cssClass":"pl-k"},{"start":105,"end":111,"cssClass":"pl-c1"}],[],[],[],[{"start":4,"end":64,"cssClass":"pl-c"},{"start":4,"end":6,"cssClass":"pl-c"}],[{"start":4,"end":10,"cssClass":"pl-c1"},{"start":26,"end":27,"cssClass":"pl-c1"}],[{"start":4,"end":10,"cssClass":"pl-c1"},{"start":27,"end":28,"cssClass":"pl-c1"},{"start":30,"end":31,"cssClass":"pl-c1"}],[{"start":4,"end":10,"cssClass":"pl-c1"},{"start":27,"end":29,"cssClass":"pl-c1"},{"start":31,"end":32,"cssClass":"pl-c1"}],[],[{"start":4,"end":15,"cssClass":"pl-c1"}],[{"start":4,"end":15,"cssClass":"pl-c1"}],[{"start":4,"end":15,"cssClass":"pl-c1"}],[],[],[{"start":4,"end":10,"cssClass":"pl-c1"},{"start":21,"end":27,"cssClass":"pl-k"}],[],[{"start":4,"end":25,"cssClass":"pl-c"},{"start":4,"end":6,"cssClass":"pl-c"}],[{"start":4,"end":10,"cssClass":"pl-c1"}],[{"start":4,"end":12,"cssClass":"pl-k"},{"start":13,"end":17,"cssClass":"pl-k"},{"start":37,"end":45,"cssClass":"pl-k"},{"start":46,"end":50,"cssClass":"pl-k"},{"start":52,"end":58,"cssClass":"pl-c1"}],[{"start":4,"end":24,"cssClass":"pl-c1"}],[],[{"start":4,"end":13,"cssClass":"pl-c1"},{"start":14,"end":30,"cssClass":"pl-s"},{"start":14,"end":15,"cssClass":"pl-pds"},{"start":29,"end":30,"cssClass":"pl-pds"}],[],[{"start":4,"end":8,"cssClass":"pl-c1"}],[],[],[{"start":0,"end":3,"cssClass":"pl-k"},{"start":4,"end":8,"cssClass":"pl-en"}],[{"start":4,"end":9,"cssClass":"pl-k"},{"start":10,"end":18,"cssClass":"pl-k"},{"start":19,"end":23,"cssClass":"pl-k"},{"start":38,"end":67,"cssClass":"pl-s"},{"start":38,"end":39,"cssClass":"pl-pds"},{"start":66,"end":67,"cssClass":"pl-pds"}],[{"start":4,"end":9,"cssClass":"pl-k"},{"start":10,"end":18,"cssClass":"pl-k"},{"start":19,"end":23,"cssClass":"pl-k"},{"start":32,"end":62,"cssClass":"pl-s"},{"start":32,"end":33,"cssClass":"pl-pds"},{"start":61,"end":62,"cssClass":"pl-pds"}],[{"start":4,"end":9,"cssClass":"pl-k"},{"start":10,"end":18,"cssClass":"pl-k"},{"start":19,"end":23,"cssClass":"pl-k"},{"start":31,"end":41,"cssClass":"pl-s"},{"start":31,"end":32,"cssClass":"pl-pds"},{"start":40,"end":41,"cssClass":"pl-pds"},{"start":43,"end":67,"cssClass":"pl-c"},{"start":43,"end":45,"cssClass":"pl-c"}],[],[{"start":4,"end":10,"cssClass":"pl-c1"},{"start":11,"end":28,"cssClass":"pl-s"},{"start":11,"end":12,"cssClass":"pl-pds"},{"start":25,"end":27,"cssClass":"pl-cce"},{"start":27,"end":28,"cssClass":"pl-pds"}],[],[{"start":4,"end":10,"cssClass":"pl-c1"},{"start":27,"end":33,"cssClass":"pl-c1"},{"start":35,"end":40,"cssClass":"pl-k"},{"start":41,"end":45,"cssClass":"pl-k"}],[],[{"start":4,"end":10,"cssClass":"pl-c1"},{"start":11,"end":36,"cssClass":"pl-s"},{"start":11,"end":12,"cssClass":"pl-pds"},{"start":33,"end":35,"cssClass":"pl-cce"},{"start":35,"end":36,"cssClass":"pl-pds"}],[],[{"start":4,"end":20,"cssClass":"pl-c1"}],[],[{"start":4,"end":10,"cssClass":"pl-k"},{"start":11,"end":12,"cssClass":"pl-c1"}],[],[]],"csv":null,"csvError":null,"dependabotInfo":{"showConfigurationBanner":false,"configFilePath":null,"networkDependabotPath":"/192110488/cryptography-and-network-security/network/updates","dismissConfigurationNoticePath":"/settings/dismiss-notice/dependabot_configuration_notice","configurationNoticeDismissed":false,"repoAlertsPath":"/192110488/cryptography-and-network-security/security/dependabot","repoSecurityAndAnalysisPath":"/192110488/cryptography-and-network-security/settings/security_analysis","repoOwnerIsOrg":false,"currentUserCanAdminRepo":false},"displayName":"19.C program for encryption in the cipher block chaining (CBC).cpp","displayUrl":"https://github.com/192110488/cryptography-and-network-security/blob/main/19.C%20program%20for%20encryption%20in%20the%20cipher%20block%20chaining%20(CBC).cpp?raw=true","headerInfo":{"blobSize":"1.63 KB","deleteInfo":{"deleteTooltip":"Fork this repository and delete the file"},"editInfo":{"editTooltip":"Fork this repository and edit the file"},"ghDesktopPath":"https://desktop.github.com","gitLfsPath":null,"onBranch":true,"shortPath":"284ebb3","siteNavLoginPath":"/login?return_to=https%3A%2F%2Fgithub.com%2F192110488%2Fcryptography-and-network-security%2Fblob%2Fmain%2F19.C%2520program%2520for%2520encryption%2520in%2520the%2520cipher%2520block%2520chaining%2520%28CBC%29.cpp","isCSV":false,"isRichtext":false,"toc":null,"lineInfo":{"truncatedLoc":"55","truncatedSloc":"40"},"mode":"file"},"image":false,"isCodeownersFile":null,"isPlain":false,"isValidLegacyIssueTemplate":false,"issueTemplateHelpUrl":"https://docs.github.com/articles/about-issue-and-pull-request-templates","issueTemplate":null,"discussionTemplate":null,"language":"C++","languageID":43,"large":false,"loggedIn":true,"newDiscussionPath":"/192110488/cryptography-and-network-security/discussions/new","newIssuePath":"/192110488/cryptography-and-network-security/issues/new","planSupportInfo":{"repoIsFork":null,"repoOwnedByCurrentUser":null,"requestFullPath":"/192110488/cryptography-and-network-security/blob/main/19.C%20program%20for%20encryption%20in%20the%20cipher%20block%20chaining%20(CBC).cpp","showFreeOrgGatedFeatureMessage":null,"showPlanSupportBanner":null,"upgradeDataAttributes":null,"upgradePath":null},"publishBannersInfo":{"dismissActionNoticePath":"/settings/dismiss-notice/publish_action_from_dockerfile","dismissStackNoticePath":"/settings/dismiss-notice/publish_stack_from_file","releasePath":"/192110488/cryptography-and-network-security/releases/new?marketplace=true","showPublishActionBanner":false,"showPublishStackBanner":false},"rawBlobUrl":"https://github.com/192110488/cryptography-and-network-security/raw/main/19.C%20program%20for%20encryption%20in%20the%20cipher%20block%20chaining%20(CBC).cpp","renderImageOrRaw":false,"richText":null,"renderedFileInfo":null,"shortPath":null,"tabSize":8,"topBannersInfo":{"overridingGlobalFundingFile":false,"globalPreferredFundingPath":null,"repoOwner":"192110488","repoName":"cryptography-and-network-security","showInvalidCitationWarning":false,"citationHelpUrl":"https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-on-github/about-citation-files","showDependabotConfigurationBanner":false,"actionsOnboardingTip":null},"truncated":false,"viewable":true,"workflowRedirectUrl":null,"symbols":{"timedOut":false,"notAnalyzed":false,"symbols":[{"name":"print_hex","kind":"function","identStart":91,"identEnd":100,"extentStart":86,"extentEnd":292,"fullyQualifiedName":"print_hex","identUtf16":{"start":{"lineNumber":5,"utf16Col":5},"end":{"lineNumber":5,"utf16Col":14}},"extentUtf16":{"start":{"lineNumber":5,"utf16Col":0},"end":{"lineNumber":11,"utf16Col":1}}},{"name":"encrypt_cbc_3des","kind":"function","identStart":301,"identEnd":317,"extentStart":296,"extentEnd":1197,"fullyQualifiedName":"encrypt_cbc_3des","identUtf16":{"start":{"lineNumber":13,"utf16Col":5},"end":{"lineNumber":13,"utf16Col":21}},"extentUtf16":{"start":{"lineNumber":13,"utf16Col":0},"end":{"lineNumber":37,"utf16Col":1}}},{"name":"main","kind":"function","identStart":1205,"identEnd":1209,"extentStart":1201,"extentEnd":1662,"fullyQualifiedName":"main","identUtf16":{"start":{"lineNumber":39,"utf16Col":4},"end":{"lineNumber":39,"utf16Col":8}},"extentUtf16":{"start":{"lineNumber":39,"utf16Col":0},"end":{"lineNumber":53,"utf16Col":1}}}]}},"copilotInfo":{"documentationUrl":"https://docs.github.com/copilot/overview-of-github-copilot/about-github-copilot-for-individuals","notices":{"codeViewPopover":{"dismissed":false,"dismissPath":"/settings/dismiss-notice/code_view_copilot_popover"}},"userAccess":{"accessAllowed":false,"hasSubscriptionEnded":false,"orgHasCFBAccess":false,"userHasCFIAccess":false,"userHasOrgs":false,"userIsOrgAdmin":false,"userIsOrgMember":false,"business":null,"featureRequestInfo":null}},"copilotAccessAllowed":false,"csrf_tokens":{"/192110488/cryptography-and-network-security/branches":{"post":"IV_Kns-3Abw8whJRMRlo0_P70mRs_-GntpftwbWWiqNvnbUiqygvGwHOxPNat8iN5kZSyF2wZSmoLPPyN6n4NQ"},"/repos/preferences":{"post":"jAkjXu7psvUR2FBzJvd3V71dgxWLH5lyIr0IEr3YQOz7jA8daCx45uQJIW5eTq0yUwyJjC5wV_uw3LanbcpKcg"}}},"title":"cryptography-and-network-security/19.C program for encryption in the cipher block chaining (CBC).cpp at main · 192110488/cryptography-and-network-security"}