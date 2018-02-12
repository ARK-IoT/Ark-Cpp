

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
    Manager(const ARK::Network& network);

  private:

    void connect(const ARK::Network& network);

};
/*  =================  */
/*  ==========================================================================  */

};
};


#endif
