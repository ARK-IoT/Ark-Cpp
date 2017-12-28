# Ark Models


## account.h
`ARK::Model::Account`
```arduino
struct Account {
  public:
    String username;
    String address;
    String publicKey;
    String vote;
    long int producedblocks;
    long int missedblocks;
    long int rate;
    double approval;
    double productivity;
};
```


## block.h
`ARK::Model::Block`
```arduino
struct Block {
  public:
    long int id;
    double version;
    long int timestamp;
    long int heigh;
    long int previousBlock;
    long int numberOfTransactions;
    long double totalAmount;
    long double totalFee;
    long int reward;
    long intpayloadLength;
    String payloadHash;
    String generatorPublicKey;
    String generatorId;
    String blockSignature;
    long int confirmations;
    long int totalForged;
};
```


## currencies.h
`ARK::Model::Currency`
```arduino
typedef struct Currency {
  public:
    String ticker;
    String name;
    String symbol;
    Currency(String _ticker, String _name, String _symbol);
    String asString()
} currency_t;
```
`ARK::Model::Currencies::Cryptocurrencies`
```arduino
  Currency ARK { "ARK", "Ark", "Ѧ" };
  Currency BTC { "BTC", "Bitcoin", "฿" };
```
`ARK::Model::Currencies::Fiat`
```arduino
  Currency USD { "USD", "United States Dollar", "$" };
  Currency EUR { "EUR", "Euro", "€" };
  Currency GBT { "GBP", "British Pound", "£" };
```


## delegate.h
`ARK::Model::Delegate`
```arduino
struct Delegate {
  public:
    String username;
    String address;
    String publicKey;
    String vote;
    long int producedblocks;
    long int missedblocks;
    long int rate;
    double approval;
    double productivity;
};
```


## error.h
`ARK::Model::Error`
```arduino
struct Error {
  public:
    bool success;
    String error;
};
```


## network.h	
`ARK::Model::Network`
```arduino
struct Network {
  public:
    String nethash;
    String token;
    String symbol;
    String explorer;
    long double version;
};
```


## peer.h
`ARK::Model::Peer`
```arduino
struct Peer {
  public:
    String ip;
    int port;
    String version;
    int errors;
    String os;
    String height;
    String status;
    double delay;
};
```


## transaction.h	
`ARK::Model::Transaction`
```arduino
struct asset_t {};
struct Transaction {
  public:
    String id;
    long int blockid;
    int type;
    long int timestamp;
    long double amount;
    long double fee;
    String senderId;
    String recipientId;
    String senderPublicKey;
    String signature;
    asset_t asset;
    long int confirmations;
};
```


## transport.h
`ARK::Model::Transport`
```arduino
struct TransportPeerHeader {
  public:
    long int id;
    long int height;
    long double version;
    long double totalAmount;
    long double totalFee;
    long double reward;
    String payloadHash;
    int payloadLength;
    long int timestamp;
    long int numberOfTransactions;
    long int previousBlock;
    String generatorPublicKey;
    String blockSignature;
}; 
```


## voter.h
`ARK::Model::Voter`
```arduino
struct Voter {
  public:
    String username;
    String address;
    String publicKey;
    long double balance;
};
```
