

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

    Manager();
    Manager(const ARK::Network& network);

  private:

    void connect(const ARK::Network& network);

};
/*************************************************/

};
};



/*************************************************
*  ARK::API::Manager
**************************************************/
ARK::API::Manager::Manager()
{
  this->connect(ARK::Network());
};
/*************************************************/


/*************************************************
*  ARK::API::Manager
**************************************************/
ARK::API::Manager::Manager(const ARK::Network& network)
{
  this->connect(network);
};
/*************************************************/


/*************************************************
*  ARK::API::Manager::connect
**************************************************/
void ARK::API::Manager::connect(const ARK::Network& network)
{
  this->netConnector = ARK::Utilities::Network::Connector(network);
};
/*************************************************/


#endif
