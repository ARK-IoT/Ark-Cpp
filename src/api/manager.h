

#ifndef MANAGER_H
#define MANAGER_H

namespace ARK
{
namespace API
{

/*  ==========================================================================  */
/*  =================  */
/*  ARK::API::Manager  */
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
    Manager(ARK::Network network);

  private:

    void connect(ARK::Network network);

};
/*  =================  */
/*  ==========================================================================  */

};
};




/*  ==========================================================================  */
/*  =================  */
/*  ARK::API::Manager  */
/*  Constructor */
ARK::API::Manager::Manager()
{
  ARK::Network network;
  this->connect(network);
};
/*  =================  */
/*  Constructor */
ARK::API::Manager::Manager(ARK::Network network)
{
  this->connect(network);
};
/*  =================  */
/*  Method */
void ARK::API::Manager::connect(ARK::Network network)
{
  this->netConnector = ARK::Utilities::Network::Connector(network);
};
/*  =================  */
/*  ==========================================================================  */


#endif
