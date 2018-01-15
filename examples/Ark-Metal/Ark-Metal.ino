#include <ark.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 

const char* ssid     = "yourSSID";
const char* password = "yourPASSWORD";


void testAccount(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Account Test ==========\n\n=====\n");

 String balance = _arkManager.accountBalance("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");
    Serial.println("balance: ");
    Serial.println(balance);
    Serial.println("\n=====\n");
    delay(500); 

  String publicKey = _arkManager.accountPublickey("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");
    Serial.println("publicKey: ");
    Serial.println(publicKey);
    Serial.println("\n=====\n");
    delay(500);

  String delegatesFee = _arkManager.accountDelegatesFee("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");
    Serial.println("delegatesFee: ");
    Serial.println(delegatesFee);
    Serial.println("\n=====\n");
    delay(500);

  String delegates = _arkManager.accountDelegates("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");
    Serial.println("delegates: ");
    Serial.println(delegates);
    Serial.println("\n=====\n");
    delay(500);

  String account = _arkManager.account("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");
    Serial.println("account: ");
    Serial.println(account);
    Serial.println();

  Serial.println("========== /Account Test ==========\n");
};





void testBlock(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Block Test ==========\n\n=====\n");

  String block = _arkManager.block("4367122150875693402");
    Serial.println("block: ");
    Serial.println(block);
    Serial.println("\n=====\n");
    delay(500);

/* needs stream->string size fix for large callbacks */
//  String blocks = _arkManager.blocks();
//    Serial.println(blocks);
//    Serial.println();
//    delay(500);


  String blockEpoch = _arkManager.blockEpoch();
    Serial.println("blockEpoch: ");
    Serial.println(blockEpoch);
    Serial.println("\n=====\n");
    delay(500);

  String blockHeight = _arkManager.blockHeight();
    Serial.println("blockHeight: ");
    Serial.println(blockHeight);
    Serial.println("\n=====\n");
    delay(500);

  String blockNethash = _arkManager.blockNethash();
    Serial.println("blockNethash: ");
    Serial.println(blockNethash);
    Serial.println("\n=====\n");
    delay(500);

  String blockFee = _arkManager.blockFee();
    Serial.println("blockFee: ");
    Serial.println(blockFee);
    Serial.println("\n=====\n");
    delay(500);

  String blockFees = _arkManager.blockFees();
    Serial.println("blockFees: ");
    Serial.println(blockFees);
    Serial.println("\n=====\n");
    delay(500);

  String blockMilestone = _arkManager.blockMilestone();
    Serial.println("blockMilestone: ");
    Serial.println(blockMilestone);
    Serial.println("\n=====\n");
    delay(500);

  String blockReward = _arkManager.blockReward();
    Serial.println("blockReward: ");
    Serial.println(blockReward);
    Serial.println("\n=====\n");
    delay(500);

  String blockSupply = _arkManager.blockSupply();
    Serial.println("blockSupply: ");
    Serial.println(blockSupply);
    Serial.println("\n=====\n");
    delay(500);

  String blockStatus = _arkManager.blockStatus();
    Serial.println("blockStatus: ");
    Serial.println(blockStatus);
    delay(500);
    
  Serial.println("\n\n========== /Block Test ==========\n");
};






void testDelegate(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Delegate Test ==========\n\n=====\n");

  String delegatesCount = _arkManager.delegatesCount();
    Serial.println("delegatesCount: ");
    Serial.println(delegatesCount);
    Serial.println("\n=====\n");
    delay(500);

  String delegateSearch = _arkManager.delegateSearch("sleepdeficit");
    Serial.println("delegateSearch: ");
    Serial.println(delegateSearch);
    Serial.println("\n=====\n");
    delay(500);

  String delegateVoters = _arkManager.delegateVoters("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");
    Serial.println("delegateVoters: ");
    Serial.println(delegateVoters);
    Serial.println("\n=====\n");
    delay(500);

  String delegateByUsername = _arkManager.delegate("sleepdeficit");
    Serial.println("delegateByUsername: ");
    Serial.println(delegateByUsername);
    Serial.println("\n=====\n");
    delay(500);
    
  String delegateByPublickey = _arkManager.delegate("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");
    Serial.println("delegateByPublickey: ");
    Serial.println(delegateByPublickey);
    Serial.println("\n=====\n");
    delay(500);

/*    BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
//  String delegates = _arkManager.delegates();
//    Serial.println("delegates: ");
//    Serial.println(delegates);
//    Serial.println("\n=====\n");
//    delay(500);

  String delegateFee = _arkManager.delegateFee();
    Serial.println("delegateFee: ");
    Serial.println(delegateFee);
    Serial.println("\n=====\n");
    delay(500);

  String delegateForgedByAccount = _arkManager.delegateForgedByAccount("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");
    Serial.println("delegateForgedByAccount: ");
    Serial.println(delegateForgedByAccount);
    Serial.println("\n=====\n");
    delay(500);

  String delegateNextForgers = _arkManager.delegateNextForgers();
    Serial.println("delegateNextForgers: ");
    Serial.println(delegateNextForgers);
    Serial.println("\n=====\n");
    delay(500);        
    
  Serial.println("========== /Delegate Test ==========\n");
};




void testLoader(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Loader Test ==========\n\n=====\n");

  String loaderStatus = _arkManager.loaderStatus();
    Serial.println("loaderStatus: ");
    Serial.println(loaderStatus);
    Serial.println("\n=====\n");
    delay(500);
      
  String loaderSync = _arkManager.loaderSync();
    Serial.println("loaderSync: ");
    Serial.println(loaderSync);
    Serial.println("\n=====\n");
    delay(500);

  String loaderAutoconfigure = _arkManager.loaderAutoconfigure();
    Serial.println("loaderAutoconfigure: ");
    Serial.println(loaderAutoconfigure);
    Serial.println("\n=====\n");
    delay(500); 
    
  Serial.println("========== /Loader Test ==========\n");
};



void testPeer(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Peer Test ==========\n\n=====\n");

  String peer = _arkManager.peer("167.114.29.55", 4002);
    Serial.println("peer: ");
    Serial.println(peer);
    Serial.println("\n=====\n");
    delay(500);
    
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~10,792 bytes  */
//  String peers = _arkManager.peers();
//    Serial.println("peers: ");
//    Serial.println(peers);
//    Serial.println("\n=====\n");
//    delay(500);
  
  String peerVersion = _arkManager.peerVersion();
    Serial.println("peerVersion: ");
    Serial.println(peerVersion);
    Serial.println("\n=====\n");
    delay(500);
    
  Serial.println("========== /Peer Test ==========\n");
};




void testSignatures(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Signatures Test ==========\n\n=====\n");
  
  String signaturesFee = _arkManager.signaturesFee();
    Serial.println("signaturesFee: ");
    Serial.println(signaturesFee);
    Serial.println();
    delay(500);
    
  Serial.println("========== /Signatures Test ==========\n");
};

void testMultiSignatures(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== MultiSignatures Test ==========\n\n=====\n");
  
  String multisignaturesPending = _arkManager.multisignaturesPending("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");
    Serial.println("multisignaturesPending: ");
    Serial.println(multisignaturesPending);
    Serial.println("\n=====\n");
    delay(500);

 /*  Only on Mainnet?  */
//  String multisignaturesAccounts = _arkManager.multisignaturesAccounts("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");
//    Serial.println("multisignaturesAccounts: ");
//    Serial.println(multisignaturesAccounts);
//    Serial.println("\n=====\n");
//    delay(500);
    
  Serial.println("========== /MultiSignatures Test ==========\n");
};





void testTransaction(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Transaction Test ==========\n\n=====\n");
  
  String transactionFromID = _arkManager.transaction("4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e"); //has vendorField value
    Serial.println("transactionFromID: ");
    Serial.println(transactionFromID);
    Serial.println("\n=====\n");
    delay(500);

/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~28,908 bytes  */
//  String transactions = _arkManager.transactions();
//    Serial.println("transactions: ");
//    Serial.println(transactions);
//    Serial.println("\n=====\n");
//    delay(500);

  String transactionUnconfirmedFromId = _arkManager.transactionUnconfirmed("4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e");
    Serial.println("transactionUnconfirmedFromId: ");
    Serial.println(transactionUnconfirmedFromId);
    Serial.println("\n=====\n");
    delay(500);
    
  String transactionsUnconfirmed = _arkManager.transactionsUnconfirmed();
    Serial.println("transactionsUnconfirmed: ");
    Serial.println(transactionsUnconfirmed);
    Serial.println("\n=====\n");
    delay(500);
    
  Serial.println("========== /Transaction Test ==========\n");
};




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);   //WiFi connection
  while (WiFi.status() != WL_CONNECTED)
  { delay(500); Serial.println("waiting for connection..."); }
  Serial.print("local IP: "); Serial.println(WiFi.localIP());

  delay(500);

  ARK::Network devnet = ARK::Constants::Networks::Devnet::model;
  ARK::API::Manager arkManager(devnet); // || arkManager.connect(mainnet);

  testAccount(arkManager);
  testBlock(arkManager);
  testDelegate(arkManager);
  testLoader(arkManager);
  testPeer(arkManager);
  testSignatures(arkManager);
  testMultiSignatures(arkManager);
  testTransaction(arkManager);
  
} 

void loop() {}
