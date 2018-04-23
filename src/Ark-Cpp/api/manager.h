

#ifndef MANAGER_H
#define MANAGER_H

<<<<<<< HEAD
#include "accountable.h"
#include "blockable.h"
#include "delegatable.h"
#include "loadable.h"
#include "multisignaturable.h"
#include "peerable.h"
#include "signaturable.h"
#include "transactionable.h"
#include "connector.h"

=======
>>>>>>> master
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
<<<<<<< HEAD

  public:
 /*************************************************
    *  ARK::API::Manager
    **************************************************/
    Manager();

/*************************************************
    *  ARK::API::Manager
    **************************************************/
    explicit Manager(const ARK::Network& network);

  private:
/*************************************************
    *  ARK::API::Manager::connect
    **************************************************/
    void connect(const ARK::Network& network);

};
/*  =================  */
/*  ==========================================================================  */
=======
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
>>>>>>> master

};
};

<<<<<<< HEAD

=======
>>>>>>> master
#endif
