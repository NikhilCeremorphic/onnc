//===- Target.h -----------------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef ONNC_TARGET_TARGET_H
#define ONNC_TARGET_TARGET_H
#include <onnc/IR/Quadruple.h>

namespace onnc {

class TargetBackend;
class TargetOptions;
class TargetRegistry;

/** \class Target
 *  \brief Target collects information of a target machine.
 */
class Target
{
public:
  typedef unsigned int (*QuadrupleMatchFnTy)(const Quadruple& pQuadruple);
  typedef TargetBackend* (*TargetBackendCtorFnTy)(const TargetOptions&);

public:
  /// Constructor. Set all member variables to nullptr.
  Target();

  const std::string& name() const { return m_Name; }

  const std::string& getShortDescription() const { return m_ShortDesc; }

  TargetBackend* createBackend(const TargetOptions& pOptions) const;

  unsigned int matchArch(const Quadruple& pQuadruple) const;

  void setMatchFn(QuadrupleMatchFnTy pFn) { m_ArchMatchFn = pFn; }

  void setBackendCtor(TargetBackendCtorFnTy pFn) { m_TargetBackendCtorFn = pFn; }

private:
  friend class onnc::TargetRegistry;

private:
  std::string m_Name;
  std::string m_ShortDesc;
  QuadrupleMatchFnTy m_ArchMatchFn;
  TargetBackendCtorFnTy m_TargetBackendCtorFn;
};

} // namespace of onnc

#endif
