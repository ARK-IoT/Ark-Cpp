

#ifndef MANAGER_H
#define MANAGER_H

namespace ARK
{
namespace API
{
/*************************************************
*  ARK::API::Manager
**************************************************/
class Manager :
    public ARK::API::Accountable,
    public ARK::API::Blockable,
    public Delegatable,
    public Loadable,
    public MultiSignaturable,
    public Peerable,
    public Signaturable,
    public Transactionable,
    virtual ARK::Utilities::Network::Connectable
{

  public:

    /*************************************************
    *  ARK::API::Manager
    **************************************************/
    Manager() { this->connect(ARK::Network()); };
    /*************************************************/

    /*************************************************
    *  ARK::API::Manager
    **************************************************/
    explicit Manager(const ARK::Network& network) { this->connect(network); };
    /*************************************************/

  private:

    /*************************************************
    *  ARK::API::Manager::connect
    **************************************************/
    void connect(const ARK::Network& network)
    {
      this->netConnector = ARK::Utilities::Network::Connector(network);
    };
    /*************************************************/
};
/*************************************************/

};
};

#endif
