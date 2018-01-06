

#ifndef api_account_h
#define api_account_h

namespace ARK {
  namespace API { 
    namespace Account {

      namespace Get {

        /*   {"success":true,"balance":"_balance","unconfirmedBalance":"_u_balance"}  */
        String balancefromJSON(String _jsonStr) {
          String balanceStr = ",\"balance\":\"";
            int balanceStrLength = balanceStr.length();
            int balanceIndex = _jsonStr.indexOf(balanceStr);
          String unconfirmedbalanceStr = "\",\"unconfirmedBalance\":\"";
            int unconfirmedbalanceStrLength = unconfirmedbalanceStr.length();
            int unconfirmedbalanceIndex = _jsonStr.indexOf(unconfirmedbalanceStr);
          String endStr = "\"}";
            int endIndex = _jsonStr.indexOf(endStr);

          String balanceCallback = _jsonStr.substring(balanceIndex + balanceStrLength, unconfirmedbalanceIndex);
          String unconfirmedbalanceCallback = _jsonStr.substring(unconfirmedbalanceIndex + unconfirmedbalanceStrLength, endIndex);
          
          return balanceCallback + " | " + unconfirmedbalanceCallback;
        };


        /*  {"success":true,"publicKey":"_pubkey"} */
        String publickeyfromJSON(String _jsonStr) {
          String pubkeyStr = ",\"publicKey\":\"";
            int pubkeyStrLength = pubkeyStr.length();
            int pubkeyIndex = _jsonStr.indexOf(pubkeyStr);
          String endStr = "\"}";
            int endIndex = _jsonStr.indexOf(endStr);
          return _jsonStr.substring(pubkeyIndex + pubkeyStrLength, endIndex);
        };


        /*  {"success":true,"fee":2500000000} */
        String delegatesFeefromJSON(String _jsonStr) {
          String feeStr = ",\"fee\":";
            int feeStrLength = feeStr.length();
            int feeIndex = _jsonStr.indexOf(feeStr);
          String endStr = "}";
            int endIndex = _jsonStr.indexOf(endStr);        
          return _jsonStr.substring(feeIndex + feeStrLength, endIndex);
        };


        /*
        { "success":true,
          "delegates":[{
            "username":"sleepdeficit",
            "address":"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
            "publicKey":"_pubKey",
            "vote":"7481085341862",
            "producedblocks":31138,
            "missedblocks":2991,
            "rate":19,
            "approval":0.06,
            "productivity":91.24
          }]
        }
        */
        String delegatesfromJSON(String _jsonStr) {
          String usernameStr = "[{\"username\":\"";
            int usernameStrLength = usernameStr.length();
            int usernameIndex = _jsonStr.indexOf(usernameStr);
          String addressStr = "\",\"address\":\"";
            int addressStrLength = addressStr.length();
            int addressIndex = _jsonStr.indexOf(addressStr);
          String publicKeyStr = "\",\"publicKey\":\"";
            int publicKeyStrLength = publicKeyStr.length();
            int publicKeyIndex = _jsonStr.indexOf(publicKeyStr);
          String voteStr = "\",\"vote\":\"";
            int voteStrLength = voteStr.length();
            int voteIndex = _jsonStr.indexOf(voteStr);
          String producedblocksStr = "\",\"producedblocks\":";
            int producedblocksStrLength = producedblocksStr.length();
            int producedblocksIndex = _jsonStr.indexOf(producedblocksStr);
          String missedblocksStr = ",\"missedblocks\":";
            int missedblocksStrLength = missedblocksStr.length();
            int missedblocksIndex = _jsonStr.indexOf(missedblocksStr);
          String rateStr = ",\"rate\":";
            int rateStrLength = rateStr.length();
            int rateIndex = _jsonStr.indexOf(rateStr);
          String approvalStr = ",\"approval\":";
            int approvalStrLength = approvalStr.length();
            int approvalIndex = _jsonStr.indexOf(approvalStr);
          String productivityStr = ",\"productivity\":";
            int productivityStrLength = productivityStr.length();
            int productivityIndex = _jsonStr.indexOf(productivityStr);
          String endStr = "}]}";
            int endIndex = _jsonStr.indexOf(endStr); 

          ARK::Model::Delegate delegate = {
            _jsonStr.substring(usernameIndex + usernameStrLength, addressIndex),
            _jsonStr.substring(addressIndex + addressStrLength, publicKeyIndex),
            _jsonStr.substring(publicKeyIndex + publicKeyStrLength, voteIndex),
            _jsonStr.substring(voteIndex + voteStrLength, producedblocksIndex),
            _jsonStr.substring(producedblocksIndex + producedblocksStrLength, missedblocksIndex).toInt(),
            _jsonStr.substring(missedblocksIndex + missedblocksStrLength, rateIndex).toInt(),
            _jsonStr.substring(rateIndex + rateStrLength, approvalIndex).toInt(),
            _jsonStr.substring(approvalIndex + approvalStrLength, productivityIndex).toFloat(),
            _jsonStr.substring(productivityIndex + productivityStrLength, endIndex).toFloat()
          };

          return delegate.getDescription();
        };


        /*
        { "success":true,
          "account":{
            "address":"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
            "unconfirmedBalance":"0",
            "balance":"0",
            "publicKey":"_pubkey",
            "unconfirmedSignature":1,
            "secondSignature":1,
            "secondPublicKey":"_spubkey",
            "multisignatures":[],
            "u_multisignatures":[]
          }
        }
        */
        String fromJSON(String _jsonStr) {
          String addressStr = "{\"address\":\"";
            int addressStrLength = addressStr.length();
            int addressIndex = _jsonStr.indexOf(addressStr);
          String unconfirmedBalanceStr = "\",\"unconfirmedBalance\":\"";
            int unconfirmedBalanceStrLength = unconfirmedBalanceStr.length();
            int unconfirmedBalanceIndex = _jsonStr.indexOf(unconfirmedBalanceStr);
          String balanceStr = "\",\"balance\":\"";
            int balanceStrLength = balanceStr.length();
            int balanceIndex = _jsonStr.indexOf(balanceStr);
          String publicKeyStr = "\",\"publicKey\":\"";
            int publicKeyStrLength = publicKeyStr.length();
            int publicKeyIndex = _jsonStr.indexOf(publicKeyStr);
          String unconfirmedSignatureStr = "\",\"unconfirmedSignature\":";
            int unconfirmedSignatureStrLength = unconfirmedSignatureStr.length();
            int unconfirmedSignatureIndex = _jsonStr.indexOf(unconfirmedSignatureStr);
          String secondSignatureStr = ",\"secondSignature\":";
            int secondSignatureStrLength = secondSignatureStr.length();
            int secondSignatureIndex = _jsonStr.indexOf(secondSignatureStr);
          String secondPublicKeyStr = ",\"secondPublicKey\":\"";
            int secondPublicKeyStrLength = secondPublicKeyStr.length();
            int secondPublicKeyIndex = _jsonStr.indexOf(secondPublicKeyStr);
          String multisignaturesStr = "\",\"multisignatures\":";
            int multisignaturesStrLength = multisignaturesStr.length();
            int multisignaturesIndex = _jsonStr.indexOf(multisignaturesStr);
          String u_multisignaturesStr = ",\"u_multisignatures\":";
            int u_multisignaturesStrLength = u_multisignaturesStr.length();
            int u_multisignaturesIndex = _jsonStr.indexOf(u_multisignaturesStr);
          String endStr = "}}";
            int endIndex = _jsonStr.indexOf(endStr);   

          ARK::Model::Account account = {
            _jsonStr.substring(addressIndex + addressStrLength, unconfirmedBalanceIndex),
            _jsonStr.substring(unconfirmedBalanceIndex + unconfirmedBalanceStrLength, balanceIndex),
            _jsonStr.substring(balanceIndex + balanceStrLength, publicKeyIndex),
            _jsonStr.substring(publicKeyIndex + publicKeyStrLength, unconfirmedSignatureIndex),
            _jsonStr.substring(unconfirmedSignatureIndex + unconfirmedSignatureStrLength, secondSignatureIndex).toInt(),
            _jsonStr.substring(secondSignatureIndex + secondSignatureStrLength, secondPublicKeyIndex).toInt(),
            _jsonStr.substring(secondPublicKeyIndex + secondPublicKeyStrLength, multisignaturesIndex),
            _jsonStr.substring(multisignaturesIndex + multisignaturesStrLength, u_multisignaturesIndex),
            _jsonStr.substring(u_multisignaturesIndex + u_multisignaturesStrLength, endIndex)
          };

          return account.getDescription();
        };


      };




      /*  /api/accounts/getBalance?address=arkAddress */
      String getBalance(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
        String uri = ARK::API::Endpoints::Account::getBalance_s;
          uri += "?address=" + _arkAddress;
        String callback = _netManager.cb(uri);
        if (callback.indexOf("false") >= 0)
          return callback;
        return ARK::API::Account::Get::balancefromJSON(callback);
      };


      /*  /api/accounts/getPublickey?address=arkAddress */
      String getPublickey(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
        String uri = ARK::API::Endpoints::Account::getPublickey_s;
          uri += "?address=" + _arkAddress;
        String callback = _netManager.cb(uri);
        if (callback.indexOf("false") >= 0)
          return callback;
        return ARK::API::Account::Get::publickeyfromJSON(callback);
      };


      /*  /api/accounts/delegates/fee?address=arkAddress  */
      String delegatesFee(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
        String uri = ARK::API::Endpoints::Account::delegatesFee_s;
          uri += "?address=" + _arkAddress;
        String callback = _netManager.cb(uri);
        if (callback.indexOf("false") >= 0)
          return callback;
        return ARK::API::Account::Get::delegatesFeefromJSON(callback);
      };


      /*  /api/accounts/delegates?address=arkAddress  */
      String delegates(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
        String uri = ARK::API::Endpoints::Account::delegates_s;
          uri += "?address=" + _arkAddress;
        String callback = _netManager.cb(uri);
        if (callback.indexOf("false") >= 0)
          return callback;
        return ARK::API::Account::Get::delegatesfromJSON(callback);
      };


      /*  /api/accounts?address=arkAddress  */
      String accounts(ARK::Utilities::Network::Manager _netManager, String _arkAddress) {
        String uri = ARK::API::Endpoints::Account::accounts_s;
          uri += "?address=" + _arkAddress;
        String callback = _netManager.cb(uri);
        if (callback.indexOf("false") >= 0)
          return callback;
        return ARK::API::Account::Get::fromJSON(callback);
      };




      namespace accounts_cb {
        // String Str = "";
        //   int StrLength = Str.length();
        //   int Index = _jsonStr.indexOf(Str);
        // String Callback = _jsonStr.substring(Index + StrLength, Index);


        struct addDelegatesResponse {
          public:
            String secret;
            String publicKey;
            String secondSecret;
        };

      };
      
      
    };
  };
};

#endif
